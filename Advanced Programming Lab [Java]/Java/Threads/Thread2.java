class Printer {
	
	/*synchronized*/ void printDocs (int numOfCopies, String nameOfdoc) {
		for (int i = 1; i <= numOfCopies; i++) {
			System.out.println("Printing documents from: "+nameOfdoc+" "+i);
		}
	}
}

class MyThread extends Thread {
	Printer pref;
	
	MyThread(Printer p) {
		pref = p;
	}
	
	@Override
	public void run() {
		//pref.printDocs(10, "Utsha.doc");
		synchronized (pref) {
			pref.printDocs(10, "Utsha.doc");

		}
	}
	
}

class YourThread extends Thread {
	Printer pref;
	
	YourThread(Printer p) {
		pref = p;
	}
	
	@Override
	public void run() {
		//pref.printDocs(10, "Argho.doc");
		synchronized (pref) {
			pref.printDocs(10, "Akib.doc");

		}
	}
	
}

public class Thread2 {

	public static void main(String[] args) {
		
		//Job 1
		System.out.println("Application Started...");
		
		//Job 2
		Printer printer = new Printer();
		MyThread myThread = new MyThread(printer);
		YourThread yourThread = new YourThread(printer);
		myThread.start();
		/*try {
			myThread.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		yourThread.start();
		
		//Job 3
		System.out.println("Application Ended...");
		
	}

}
