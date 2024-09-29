class MyTask extends Thread {
	
	@Override
	public void run(){
		for(int doc=1; doc<=10; doc++) {
			System.out.println("Hello again "+doc);
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
}



public class Thread1{

	public static void main(String[] args) {
		
		//Job 1
		System.out.println("Application Started...");
		
		
		MyTask myTask = new MyTask();
		myTask.start();
		
		//Job 2
		for(int doc=1; doc<=10; doc++) {
			System.out.println("Hello "+doc);
		}
		
		//Job 3
		System.out.println("Application Ended...");
		
	}

}
