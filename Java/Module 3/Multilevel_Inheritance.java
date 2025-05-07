class Animal 
{
    void makeSound() 
    {
        System.out.println("Animal makes a sound");
    }
}

class Mammal extends Animal 
{
    @Override
    void makeSound() 
    {
        System.out.println("Mammal makes a sound");
    }
}

class Dog extends Mammal 
{
    @Override
    void makeSound() 
    {
        System.out.println("Dog barks!!!");
    }
}

public class Multilevel_Inheritance 
{
    public static void main(String[] args) 
    {
        Dog myDog = new Dog();    
        myDog.makeSound();       
    }
}
