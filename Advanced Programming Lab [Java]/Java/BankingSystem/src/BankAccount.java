
public class BankAccount {
	private String AccountName;
	private int AccountNumber;
	private double AccountBalance;
	private String AccountType;
	
	BankAccount(String accname, int accnumber, double accbalance, String acctype ){
		AccountName = accname;
		AccountNumber = accnumber;
		AccountBalance = accbalance;
		AccountType = acctype;	
	}
	
	public void DepositAmount(int amount) {
		AccountBalance =  AccountBalance + amount;
	}
	
	public void WithdrawAmount(int amount) {
		AccountBalance =  AccountBalance - amount;
	}
	
	public void Display() {
		System.out.println("Account Name: "+AccountName);
		System.out.println("Account Number: "+AccountNumber);
		System.out.println("Account Type: "+AccountType);
		System.out.println("Account Balance: "+AccountBalance);
	}
	
	public String GetAccountType() {
		return AccountType;
	}
	
	public double GetBalance() {
		return AccountBalance;
	}
	
}
