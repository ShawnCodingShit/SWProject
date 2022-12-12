import java.util.Scanner;

public class Bankaccount {
    public static void main(String[] args) {
        Bank bank = new Bank();
        bank.createAccount();
        bank.login();
        bank.deposit();
        bank.withdraw();
        bank.transfer();
    }
}

class Bank {
    private String account;
    private String password;
    private double balance;
    private String name;
    private String id;
    private String phone;
    private String address;

    public void createAccount() {
        Scanner input = new Scanner(System.in);
        System.out.println("请输入账户：");
        account = input.next();
        System.out.println("请输入密码：");
        password = input.next();
        System.out.println("请输入姓名：");
        name = input.next();
        System.out.println("请输入身份证号：");
        id = input.next();
        System.out.println("请输入电话号码：");
        phone = input.next();
        System.out.println("请输入地址：");
        address = input.next();
        System.out.println("创建账户成功！");
    }

    public void login() {
        Scanner input = new Scanner(System.in);
        System.out.println("请输入账户：");
        String account = input.next();
        System.out.println("请输入密码：");
        String password = input.next();
        if (account.equals(this.account) && password.equals(this.password)) {
            System.out.println("登录成功！");
        } else {
            System.out.println("登录失败！");
        }
    }

    public void deposit() {
        Scanner input = new Scanner(System.in);
        System.out.println("请输入存款金额：");
        double money = input.nextDouble();
        balance += money;
        System.out.println("存款成功！");
    }

    public void withdraw() {
        Scanner input = new Scanner(System.in);
        System.out.println("请输入取款金额：");
        double money = input.nextDouble();
        if (money > balance) {
            try {
                throw new BankException("余额不足！");
            } catch (BankException e) {
                e.printStackTrace();
            }
        } else {
            balance -= money;
            System.out.println("取款成功！");
        }
    }

    public void transfer() {
        Scanner input = new Scanner(System.in);
        System.out.println("请输入转账金额：");
        double money = input.nextDouble();
        if (money > balance) {
            try {
                throw new BankException("余额不足！");
            } catch (BankException e) {
                e.printStackTrace();
            }
        } else {
            balance -= money;
            System.out.println("转账成功！");
        }
    }
}
