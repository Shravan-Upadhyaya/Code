class BankAccount {
    private String accountNumber;
    private String accountHolderName;
    private double balance;

    public BankAccount(String accountNumber, String accountHolderName, double balance) {
        this.accountNumber = accountNumber;
        this.accountHolderName = accountHolderName;
        this.balance = balance;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited " + amount + ". New balance: " + balance);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn " + amount + ". New balance: " + balance);
        } else {
            System.out.println("Insufficient funds or invalid withdrawal amount.");
        }
    }

    public void transfer(BankAccount targetAccount, double amount) {
        if (amount > 0 && amount <= balance) {
            this.withdraw(amount);
            targetAccount.deposit(amount);
            System.out.println("Transferred " + amount + " to " + targetAccount.accountHolderName);
        } else {
            System.out.println("Transfer failed: Insufficient funds or invalid amount.");
        }
    }

    public void displayAccountDetails() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Account Holder: " + accountHolderName);
        System.out.println("Balance: " + balance);
    }
}

public class Bank_Account {
    public static void main(String[] args) {
        BankAccount account1 = new BankAccount("123456", "James Bond", 500.0);
        BankAccount account2 = new BankAccount("789101", "Mr India", 300.0);
        
        account1.deposit(200);
        account1.withdraw(100);
        account1.transfer(account2, 150);
        
        System.out.println("\nAccount Details After Transactions:");
        account1.displayAccountDetails();
        account2.displayAccountDetails();
        
        BankAccount account3 = account1; 
        account3.deposit(50);
        
        System.out.println("\nAccount Details After Reference Sharing:");
        account1.displayAccountDetails();
        account3.displayAccountDetails();
        
        account1 = null;
        System.gc();
        System.out.println("\nAccount1 is now eligible for garbage collection.");
    }
}
