# Laboratory Work Nr.2

### Course: Software Design Techniques and Mechanisms
### Topic: Creational Design Patterns
### Author: Iațco Sorin
----

## Theory
Creational design patterns are a category of design patterns that focus on the process of object creation. They provide a way to create objects in a flexible and controlled manner, while decoupling the client code from the specifics of object creation. Creational design patterns address common problems encountered in object creation, such as how to create objects with different initialization parameters, how to create objects based on certain conditions, or how to ensure that only a single instance of an object is created. There are several creational design patterns that have their own strengths and weaknesses. Each of it is best suited for solving specific problems related to object creation. By using creational design patterns, developers can improve the flexibility, maintainability, and scalability of their code.

## Objectives:

1. Study and understand the Creational Design Patterns.
2. Choose a domain, define its main classes/models/entities and choose the appropriate instantiation mechanisms.
3. Use some creational design patterns for object instantiation in a sample project.


## Implementation description

### Project domain
The project main idea is a car manufacturer that have a lot of dealerships and in each dealership the staff needs acces to the vehicles information for customers or for the dealership itself. Also thy are having acces to company advertisements, customers, factory and staff. The project is structured in 4 main packages: assembly-line, carmanufacturing, marketing and personnel. Each package contains classes that are related to the package name. The main idea of the project is to show how the SOLID principles are respected in the project and introduce different design patterns.

### Creational Patterns
#### Singleton
This code ensures that there is only one instance of the `Customer` class, and you can retrieve that instance using the `GetInstance` method. This makes it a Singleton design pattern implementation. The use of a mutex ensures thread safety when accessing and modifying the list of instances, making it safe for use in a multi-threaded environment.
```
Customer* Customer::GetInstance(const std::string& name, int age)
{
    std::lock_guard<std::mutex> lock(mutex_);
    for (Customer* customer : instances_) {
        if (customer->GetName() == name && customer->GetAge() == age) {
            return customer;
        }
    }
    auto* newCustomer = new Customer(name, age);
    instances_.push_back(newCustomer);
    return newCustomer;
}
```

#### Builder
With this architecture, you can create different builder classes (e.g., `ElectricCarBuilder`, `SportsCarBuilder`, `OffroadCarBuilder`) to construct different types of cars, each with its own implementation of how to build the various parts. The `Assembly` class acts as the central coordinator to build the car, and it allows you to create cars with different configurations by choosing the appropriate builder.

#### Factory
With this architecture, I can create different concrete factory classes (e.g., `SedanFactory`, `SUVFactory`) to produce different types of car objects (e.g., `Sedan`, `Offroad`). Each concrete factory is responsible for creating a specific type of product.
The provided code represents the Factory Method design pattern by defining a factory interface (CarFactory), concrete product classes (Sedan), and concrete factory classes (SedanFactory) that create instances of the product class. This pattern allows for the creation of different types of cars while encapsulating the object creation logic within the appropriate factories.
```
CarInterface* SedanFactory::CreateCar(std::string brand, std::string model, int year, std::string features, double price, int quantity, std::string serialNr) const {
    return new Sedan(brand, model, year, features, price, quantity, serialNr);
}
```

#### Prototype
By using the Prototype pattern in this code, I can easily create new instances of `Manager` and `Developer` employees by cloning the corresponding prototype object. This approach allows me to create new employees with the same characteristics as existing ones without having to explicitly set all the attributes again.
The code demonstrates the Prototype pattern by defining an abstract base class `Employee` and concrete derived classes `Manager` and `Developer` as prototypes. The `EmployeeFactory` uses these prototypes to create new instances of employees with the same characteristics as the prototypes, facilitating object creation and customization.
```
Manager::Manager(std::string name, int id, int team_size)
        : Employee(std::move(name), id, MANAGER), team_size_(team_size) {}

Employee* Manager::Clone() const {
    return new Manager(*this);
}
```
## Conclusions / Results

### Conclusion
In conclusion, the laboratory work focused on implementing Creational design patterns, specifically Singleton, Builder, Factory, and Prototype patterns, has been a valuable learning experience in software design and architecture. These design patterns are fundamental in ensuring the creation of objects and managing object instantiation in a flexible and efficient manner.

Finally, the laboratory work demonstrated how Creational design patterns can greatly enhance the flexibility, maintainability, and efficiency of software systems. The Singleton pattern ensured single instances where needed, the Builder pattern simplified complex object creation, the Factory pattern promoted extensibility, and the Prototype pattern optimized object creation processes. By understanding and applying these design patterns, I have gained valuable insights into best practices for object creation and instantiation, which will undoubtedly contribute to the development of robust and maintainable software in the future.

## References
https://github.com/sspatari/tmps-labs/tree/master/Lab%232