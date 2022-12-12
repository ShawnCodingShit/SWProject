import java.util.Scanner;

public class FinalBank {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Bank bank = new Bank();
        int choice;
        do {
            System.out.println("1.Create an account");
            System.out.println("2.deposit");
            System.out.println("3.withdraw");
            System.out.println("4.transfer");
            System.out.println("5.query balance");
            System.out.println("6.close account");
            System.out.println("7.exit");
            System.out.print("Enter your choice:");
            choice = input.nextInt();
            switch (choice) {
                case 1:
                    bank.openAccount();
                    break;
                case 2:
                    bank.deposit();
                    break;
                case 3:
                    bank.withdraw();
                    break;
                case 4:
                    bank.transfer();
                    break;
                case 5:
                    bank.queryBalance();
                    break;
                case 6:
                    bank.closeAccount();
                    break;
                case 7:
                    System.out.println("Thanks for ur using bro!!!!!!");
                    break;
                default:
                    System.out.println("Invalid choice dude ,plz check again!!!!");
            }
        } while (choice != 7);
    }
}

//Bank
class Bank {
    private Account[] accounts = new Account[100];
    private int count = 0;

    public void openAccount() {
        Scanner input = new Scanner(System.in);
        System.out.print("please enter your name:");
        String name = input.next();
        System.out.print("please enter your id:");
        String id = input.next();
        System.out.print("please enter your balance:");
        double balance = input.nextDouble();
        Account account = new Account(name, id, balance);
        accounts[count] = account;
        count++;
        System.out.println("Account created successfully!");
    }

    //deposit
    public void deposit() {
        Scanner input = new Scanner(System.in);
        System.out.print("please enter your id:");
        String id = input.next();
        System.out.print("please enter your balance:");
        double balance = input.nextDouble();
        for (int i = 0; i < count; i++) {
            if (accounts[i].getId().equals(id)) {
                accounts[i].deposit(balance);
                System.out.println("Deposit successfully!");
                return;
            }
        }
        System.out.println("Account does not exist!");
    }

    //withdraw
    public void withdraw() {
        Scanner input = new Scanner(System.in);
        System.out.print("please enter your id:");
        String id = input.next();
        System.out.print("please enter your balance:");
        double balance = input.nextDouble();
        for (int i = 0; i < count; i++) {
            if (accounts[i].getId().equals(id)) {
                accounts[i].withdraw(balance);
                System.out.println("Withdraw successfully!");
                return;
            }
        }
        System.out.println("Account does not exist!");
    }

    //transfer
    public void transfer() {
        Scanner input = new Scanner(System.in);
        System.out.print("transfer out account");
        String id1 = input.next();
        System.out.print("transfer in account");
        String id2 = input.next();
        System.out.print("Please enter the transfer amount:");
        double balance = input.nextDouble();
        for (int i = 0; i < count; i++) {
            if (accounts[i].getId().equals(id1)) {
                for (int j = 0; j < count; j++) {
                    if (accounts[j].getId().equals(id2)) {
                        accounts[i].withdraw(balance);
                        accounts[j].deposit(balance);
                        System.out.println("Transfer successfully!");
                        return;
                    }
                }
                System.out.println("The transfer account does not exist!");
                return;
            }
        }
        
        System.out.println("The transfer account does not exist!");
    }

    //queryBalance
    public void queryBalance() {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter the query account number:");
        String id = input.next();
        for (int i = 0; i < count; i++) {
            if (accounts[i].getId().equals(id)) {
                System.out.println("accounts" + accounts[i].getId() + " balance" + accounts[i].getBalance());
                return;
            }
        }
        System.out.println("Account does not exist!");
    }

    //closeAccount
    public void closeAccount() {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter the account number to be closed:");
        String id = input.next();
        for (int i = 0; i < count; i++) {
            if (accounts[i].getId().equals(id)) {
                accounts[i] = accounts[count - 1];
                accounts[count - 1] = null;
                count--;
                System.out.println("Account closed successfully!");
                return;
            }
        }
        System.out.println("Account does not exist!");
    }
}

//Account
class Account {
    private String name;
    private String id;
    private double balance;

    public Account(String name, String id, double balance) {
        this.name = name;
        this.id = id;
        this.balance = balance;
    }

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }

    public double getBalance() {
        return balance;
    }

    public void deposit(double balance) {
        this.balance += balance;
    }

    public void withdraw(double balance) {
        this.balance -= balance;
    }
}
