public class Hotel {
    private String hotelID;
    private String Location;
    private int hotelType;
    private int costPerRoom;
    private String roomType;
    private int totalRooms;
    private int availableRooms;

    public Hotel(String hotelID, String Location, int hotelType, int costPerRoom, String roomType, int totalRooms, int availableRooms){
        this.hotelID = hotelID;
        this.Location = Location;
        this.hotelType = hotelType; // 3, r or 5
        this.costPerRoom = costPerRoom;
        this.roomType = roomType; // "Normal", "Deluxe" or "Premium"
        this.totalRooms = totalRooms;
        this.availableRooms = availableRooms;
    }

    public double getDiscount() {
        if(hotelType == 4 || hotelType == 5){
            if(roomType == "Normal"){
                return 0.05;
            }
            else if(roomType == "Deluxe"){
                return 0.15;
            }
            else if(roomType == "Premium"){
                return 0.20;
            }
            else{
                return 0;
            }
        }
        return 0;
    }

    public void bookRoom(){
        if(availableRooms > 0){
            availableRooms--;
        }
        else{
            System.out.println("No Rooms Available");
        }
    }

    public void cancelRoom(){
        if(availableRooms == totalRooms){
            System.out.println("There is no booked room right now");
        }
        else{
            availableRooms++;
        }
    }

    public string getID() {
        return hotelID;
    }

    public void displayDetails() {
        System.out.println();
        System.out.println("Hotel ID : " + hotelID);
        System.out.println("Location : " + Location);
        System.out.println("Hotel Type : " + hotelType);
        System.out.println("Room Type : " + roomType);
        System.out.println("Cost Per Room : " + costPerRoom);
        System.out.println("Discounted Price : " + (costPerRoom - costPerRoom * getDiscount()));
        System.out.println("Total Rooms : " + totalRooms);
        System.out.println("Available Romms : " + availableRooms);
        System.out.println();

    }
}
