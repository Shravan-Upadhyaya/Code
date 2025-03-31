public class Q9 {
        public static void main(String[] args) {
            System.out.println("Even numbers between 1 and 50 using a for loop:");
            for (int i = 2; i <= 50; i += 2) {
                System.out.print(i + " ");
            }
            System.out.println("\n");
    
            System.out.println("Even numbers between 1 and 50 using a while loop:");
            int num = 2;
            while (num <= 50) {
                System.out.print(num + " ");
                num += 2;
            }
            System.out.println("\n");
    
            System.out.println("Even numbers between 1 and 50 using a do-while loop:");
            int counter = 2;
            do {
                System.out.print(counter + " ");
                counter += 2;
            } while (counter <= 50);
            System.out.println();
        
    }
    
}
