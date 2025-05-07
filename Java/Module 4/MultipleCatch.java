public class MultipleCatch
{
    public static void main(String[] args) 
    {
        try {
            int[] numbers = {1, 2, 3};
            System.out.println(numbers[5]);

            int result = 10 / 0;

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Caught ArrayIndexOutOfBoundsException: " + e.getMessage());
        } catch (ArithmeticException e) {
            System.out.println("Caught ArithmeticException: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Caught Exception: " + e.getMessage());
        }finally {
            System.out.println("Finally block executed");
        }
    }
}
