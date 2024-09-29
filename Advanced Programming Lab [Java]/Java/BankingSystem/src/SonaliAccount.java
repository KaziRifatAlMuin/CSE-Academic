
public class SonaliAccount extends BankAccount implements GetInterest {

	SonaliAccount(String accname, int accnumber, double accbalance, String acctype) {
		super(accname, accnumber, accbalance, acctype);
	}

	public double getInterestForFixedDeposit(double balance) {
		return balance*0.2;
	}
	
}
