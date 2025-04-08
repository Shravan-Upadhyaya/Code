public class Q6{
    public static void main(String[] args) {
        int intValue = 42;
        double doubleValue = intValue;
        System.out.println("Implicitly casted int to double: " + doubleValue);

        double originalDouble = 42.99;
        int castedInt = (int) originalDouble;
        System.out.println("Explicitly casted double to int: " + castedInt);

        byte byteValue = 10;
        short shortValue = 20;
        int mixedResult = byteValue + shortValue;
        double finalResult = mixedResult * 2.5;

        System.out.println("Result of mixed type expression (byte + short): " + mixedResult);
        System.out.println("Final result after multiplying by 2.5: " + finalResult);
    }
}