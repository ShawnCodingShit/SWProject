class BankAccount {
	
	private int balance;
	private int TRANSFER_FEE = 1;
	private boolean frozen; 
	
	public BankAccount(int initial_amount) {
		balance = initial_amount;
        frozen = false;
	}
	
	public boolean deposit(int amount) {
        if (frozen) {
            return false;
        }
        balance = balance + amount;
        return true;
	}
	  
	public boolean withdraw(int amount) { 
        if (frozen) {
            return false;
        }
        if (balance < amount) {
            return false;
        }
        balance = balance - amount;
        return true;
	}

	public boolean transfer(int amount, BankAccount other) {
	
        if (frozen) {
            return false;
        }
        if (balance < amount + 1) {
            return false;
        }
        if (other.frozen) {
            return false;
        }
        balance = balance - amount - TRANSFER_FEE;
        other.balance = other.balance + amount;
        return true;


	}
	
	public void freeze() {
        frozen = true;
	} 
	
	public boolean isFrozen() {
            return frozen;

	}
	
	public int getBalance() {
            return balance;
	}	
}

public class SWGithubGroup {

	public static void main(String[] args) {
		
		BankAccount account1 = new BankAccount(10000);
		BankAccount account2 = new BankAccount(10);
		System.out.println(account1.transfer(10000, account2));  
		System.out.println(account1.transfer(95, account2));  
		System.out.println("account 1: " + account1.getBalance()); 
		System.out.println("account 2: " + account2.getBalance()); 
		System.out.println(account1.transfer(58, account2)); 
		System.out.println("account 1: " + account1.getBalance()); 
		System.out.println("account 2: " + account2.getBalance()); 
        account2.freeze();
        System.out.println(account1.transfer(69, account2));
        System.out.println("account 1: " + account1.getBalance());
        System.out.println("account 2: " + account2.getBalance());
	}

}