public class HotelSystem {
    public static void main(String[] args) {
        Hotel A = new Hotel("HTH23", "Khulna", 4, 1000, "Deluxe", 250, 10);
        Hotel B = new Hotel("HTH26", "Dhaka", 5, 2000, "Premium", 500, 20);
        Hotel C = new Hotel("ABC21", "Sylhet", 3, 1200, "Normal", 100, 30);

        A.bookRoom();
        A.bookRoom();
        A.bookRoom();
        A.cancelRoom();
        A.displayDetails();

        B.bookRoom();
        B.cancelRoom();
        B.cancelRoom();
        B.cancelRoom();
        B.cancelRoom();
        B.displayDetails();

        C.bookRoom();
        C.displayDetails();

        System.out.println("Running");
    }
}