public class BankingSystem {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//BankAccount Utsha = new BankAccount("Utsha", 1407011, 500.00, "SAVINGS");
		
		JanataAccount Utsha = new JanataAccount("Utsha", 1407011, 500.00, "SAVINGS");
		
		Utsha.DepositAmount(1000);
		//Utsha.Display();
		Utsha.WithdrawAmount(200);
		//Utsha.Display();
		String acctype = Utsha.GetAccountType();
		double accbalance = Utsha.GetBalance();
		double interest=0;
		if(acctype=="SAVINGS")interest=Utsha.GetInterestForSavings(accbalance);
		else if(acctype=="FIXED DEPOSIT")interest=Utsha.getInterestForFixedDeposit(accbalance);
		else interest=0;
		System.out.println("Type: "+acctype+"\nBalance:" + accbalance+"\nInterest:"+interest);
		
	}

}
