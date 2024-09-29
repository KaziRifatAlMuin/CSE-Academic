
public interface GetInterest {
	
	public double getInterestForFixedDeposit(double balance);
	
	default public double GetInterestForSavings(double balance) {
		return balance*0.1;
	}
	
}
