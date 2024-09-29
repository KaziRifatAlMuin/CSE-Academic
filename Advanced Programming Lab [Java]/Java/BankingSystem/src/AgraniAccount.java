
public class AgraniAccount extends BankAccount implements GetInterest {

	AgraniAccount(String accname, int accnumber, double accbalance, String acctype) {
		super(accname, accnumber, accbalance, acctype);
	}
	
	public double getInterestForFixedDeposit(double balance) {
		return balance*0.25;
	}

}
