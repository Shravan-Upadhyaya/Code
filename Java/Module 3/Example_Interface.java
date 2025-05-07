interface Printable 
{
    void print();
}

class Document implements Printable 
{
    public void print() 
    {
        System.out.println("Printing document...");
    }
}

class Image implements Printable 
{
    public void print() 
    {
        System.out.println("Printing image...");
    }
}
public class Example_Interface
{
    public static void main(String[] args) 
    {
        Printable doc=new Document();
        doc.print();
        Printable img=new Image();  
        img.print();
    }
}
