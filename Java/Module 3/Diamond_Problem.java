interface A
{
    default void print() 
    {
        System.out.println("Hii from A");
    }
}

interface B extends A 
{
    default void print() 
    {
        System.out.println("Hii from B");
    }
}

interface C extends A 
{
    default void print() 
    {
        System.out.println("Hii from C");
    }
}

class D implements B, C 
{
    public void print() 
    {   C.super.print();
        B.super.print();
        System.out.println("Hii from D");
    }
}

public class Diamond_Problem 
{
    public static void main(String[] args) 
    {
        D obj = new D();
        obj.print();
    }
}
