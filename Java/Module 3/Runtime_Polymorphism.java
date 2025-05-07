abstract class Vehicle 
{
    abstract void speed();
}

class Car extends Vehicle 
{
    @Override
    void speed() 
    {
        System.out.println("Car speed: 170 km/h");
    }
}

class Bike extends Vehicle 
{
    @Override
    void speed() 
    {
        System.out.println("Bike speed: 99 km/h");
    }
}

public class Runtime_Polymorphism
{
    public static void main(String[] args) 
    {
        Vehicle myVehicle = new Car();
        myVehicle.speed();
        myVehicle = new Bike();
        myVehicle.speed(); 
    }
}

