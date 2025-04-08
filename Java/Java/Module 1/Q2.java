public class Q2{
    public static void main(String[] args) {
        System.out.println("Welcome to Java Programming!");
        var intValue = 25;
        var doubleValue = 15.75; 
        var stringValue = "Hello, ";
        var charValue = 'B';
        var sum = intValue + (int)doubleValue; 
        var product = intValue * 2;
        var concatenatedString = stringValue + "World!";
        System.out.println("Sum of intValue and doubleValue (casted): " + sum);
        System.out.println("Product of intValue and 2: " + product);
        System.out.println("Concatenated String: " + concatenatedString);
        System.out.println("Char value: " + charValue);
    }
}