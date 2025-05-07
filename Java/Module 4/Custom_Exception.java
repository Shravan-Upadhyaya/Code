class Insufficient_Balance extends Exception 
{
    public Insufficient_Balance(String message) 
    {
        super(message);
    }
}

public class Custom_Exception 
{
    private double balance;

    public Custom_Exception(double initial) 
    {
        this.balance = initial;
    }

    public void withdraw(double amount) throws Insufficient_Balance 
    {
        if (amount > balance) 
        {
            throw new Insufficient_Balance("Withdrawal denied: Insufficient balance.");
        } else 
        {
            balance -= amount;
            System.out.println("Withdrawal successful. Remaining balance: $" + balance);
        }
    }

    public static void main(String[] args) 
    {
        Custom_Exception account = new Custom_Exception(500.00);

        try {
            System.out.println("Trying to withdraw $100...");
            account.withdraw(100.00);
        } catch (Insufficient_Balance e) {
            System.out.println("Caught custom exception: " + e.getMessage());
        }

        try {
            System.out.println("Trying to withdraw $600...");
            account.withdraw(600.00);
        } catch (Insufficient_Balance e) {
            System.out.println("Caught custom exception: " + e.getMessage());
        }

        System.out.println("Transaction complete.");
    }
}
