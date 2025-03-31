public class Q5 {
    public static void main(String[] args) {
        int value = 0;

        System.out.println("Using pre-increment:");
        for (int i = 1; i <= 10; ++i) 
        { 
            value = i;
            System.out.println("Value: " + value);
        }

        System.out.println("\nUsing post-increment:");
        value = 0; // Reset value
        for (int i = 0; i < 10; i++) 
        {
            value = i + 1;
            System.out.println("Value: " + value);
        }
    }
}