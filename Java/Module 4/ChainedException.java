public class ChainedException 
{

    static void divide(int a, int b) 
    {
        try {
            int result = a / b;
        } catch (ArithmeticException e) 
        {
            throw new RuntimeException("Error occurred in divide method", e);
        }
    }

    public static void main(String[] args) 
    {
        try {
            divide(10, 0);
        } catch (RuntimeException e) {
            System.out.println("Chained Exception Caught: " + e.getMessage());
            Throwable cause = e.getCause();
            System.out.println("Original cause: " + cause);
        }finally{
            System.out.println("Finally block executed");
        }
    }
}
