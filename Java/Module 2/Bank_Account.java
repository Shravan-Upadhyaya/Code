import java.util.Scanner;

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
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter details for Account 1:");
        System.out.print("Account Number: ");
        String accountNumber1 = scanner.nextLine();
        System.out.print("Account Holder Name: ");
        String accountHolderName1 = scanner.nextLine();
        System.out.print("Initial Balance: ");
        double balance1 = scanner.nextDouble();
        scanner.nextLine(); // Consume the leftover newline

        BankAccount account1 = new BankAccount(accountNumber1, accountHolderName1, balance1);

        System.out.println("Enter details for Account 2:");
        System.out.print("Account Number: ");
        String accountNumber2 = scanner.nextLine();
        System.out.print("Account Holder Name: ");
        String accountHolderName2 = scanner.nextLine();
        System.out.print("Initial Balance: ");
        double balance2 = scanner.nextDouble();
        scanner.nextLine();

        BankAccount account2 = new BankAccount(accountNumber2, accountHolderName2, balance2);

        System.out.println("\nChoose an operation:");
        System.out.println("1. Deposit to Account 1");
        System.out.println("2. Withdraw from Account 1");
        System.out.println("3. Transfer from Account 1 to Account 2");
        System.out.println("4. Display Account Details");
        System.out.println("5. Exit");

        int choice;
        do {
            System.out.print("\nEnter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter deposit amount: ");
                    double depositAmount = scanner.nextDouble();
                    account1.deposit(depositAmount);
                    break;
                case 2:
                    System.out.print("Enter withdrawal amount: ");
                    double withdrawalAmount = scanner.nextDouble();
                    account1.withdraw(withdrawalAmount);
                    break;
                case 3:
                    System.out.print("Enter transfer amount: ");
                    double transferAmount = scanner.nextDouble();
                    account1.transfer(account2, transferAmount);
                    break;
                case 4:
                    System.out.println("\nAccount 1 Details:");
                    account1.displayAccountDetails();
                    System.out.println("\nAccount 2 Details:");
                    account2.displayAccountDetails();
                    break;
                case 5:
                    System.out.println("Exiting program. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 5);

        scanner.close();
    }
}