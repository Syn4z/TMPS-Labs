# Laboratory Work Nr.1

### Course: Software Design Techniques and Mechanisms
### Topic: SOLID Principles
### Author: Iațco Sorin
----

## Theory
SOLID is a set of five object-oriented design principles intended to make software designs more maintainable, flexible, and easy to understand. The acronym stands for Single Responsibility Principle, Open-Closed Principle, Liskov Substitution Principle, Interface Segregation Principle, and Dependency Inversion Principle. Each principle addresses a specific aspect of software design, such as the organization of responsibilities, the handling of dependencies, and the design of interfaces. By following these principles, software developers can create more modular, testable, and reusable code that is easier to modify and extend over time. These principles are widely accepted and adopted in the software development community and can be applied to any object-oriented programming language.


## Objectives:

1. Choose an OO programming language and a suitable IDE or Editor (No frameworks/libs/engines allowed).
2. Select a domain area for the sample project.
3. Define the main involved classes and think about what instantiation mechanisms are needed.
4. Respect SOLID Principles in your project.


## Implementation description

### Project domain
The project main idea is a car manufacturer that have a lot of dealerships and in each dealership the staff needs acces to the vehicles information for customers or for the dealership itself. Also thy are having acces to company advertisements, customers and suppliers/partners. The project is structured in 3 main packages: carmanufacturing, marketing and supply. Each package contains classes that are related to the package name. The main idea of the project is to show how the SOLID principles are respected in the project and introduce different design patterns.

### SOLID Principles
#### Single Responsibility Principle
The Single Responsibility Principle states that each software module should have one and only one reason to change. In other words, a class should have one and only one responsibility. If a class has more than one responsibility, it becomes coupled. In this project the SRP principle is respected because each class has only one responsibility. For example the `CarImpl` class has just one responsability and will change if and just if the whole logic of the project will change, there are different classes for different logic related to this class, for example printing the information which is done by the `CarInfoDisplay` class and computing the costs of a car which is done by another class `CarCosts`.

```
CarImpl::CarImpl(const std::string& brand, const std::string& model, int year, const std::string features, double price, int quantity, const std::string& serialNr) : 
    brand(brand), model(model), year(year), features(features), price(price), quantity(quantity), serialNr(serialNr) {}
std::string CarImpl::getBrand() const { return brand; }
std::string CarImpl::getModel() const { return model; }
int CarImpl::getYear() const { return year; }
std::string CarImpl::getFeatures() const { return features; }
double CarImpl::getPrice() const { return price; }
int CarImpl::getQuantity() const { return quantity; }
std::string CarImpl::getSerialNr() const { return serialNr; }
void CarImpl::setQuantity(int newQuantity) { quantity = newQuantity; }
```

#### Open-Closed Principle
The Open-Closed Principle states that software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification. This means that a class should be extendable without modifying the class itself. In this project the OCP principle is respected because the `CarImpl` class is open for extension, for example if we want to add a new car model we can do it by extending the `CarImpl` class and adding the new model. Another example of respecting this principle is the `CarCosts` class that is open for extension because we can add new costs for the car without modifying the class itself, we just need to extend it and add the new costs.

#### Liskov Substitution Principle
The Liskov Substitution Principle states that objects in a program should be replaceable with instances of their subtypes without changing the correctness of that program. In other words, if `ComercialCar` is a subtype of `CarImpl`, then objects of type `CarImpl` may be replaced with objects of type `ComercialCar` without altering any of the desirable properties of the program. This principle applies to inheritance hierarchies, for example if we have the class `CarImpl` and we extend it to `ComercialCar` class, we can use the `ComercialCar` class instead of the `CarImpl` class without altering the correctness of the program. In this project the LSP principle is respected because we can use the `ComercialCar` class instead of the `CarImpl` class without corrupting the rest of the program. Another point proven by this project is that we can use `CarInfoDisplay` class which expects an object of type `CarImpl` and we can pass an object of type `ComercialCar` without any problem.

```
class CarInfoDisplay {
public:
    CarInfoDisplay(const CarImpl& car) : car(car) {}
    ...
```
```
ComercialCar comercialCar("Toyota", "Tundra", 2021, "POWER", 25000.0, 11, "T2123C001", "FireTruck");
    CarInfoDisplay comercialCarInfoDisplay(comercialCar);
```

#### Interface Segregation Principle
The Interface Segregation Principle states that clients should not be forced to depend upon interfaces that they do not use. This principle deals with the disadvantages of implementing big interfaces. In this project the ISP principle is respected because we have a lot of interfaces that are used by different classes. For example the `Advertisement` interface is used by the `FreeAdvertisement` interface and the `PaidAdvertisement` interface, so the interfaces are kept separated for each specific functions needed. In this way we can implement the interfaces that we need without implementing the whole interface. Instead of having a big general interface `Advertisement` we have two smaller interfaces `FreeAdvertisement` and `PaidAdvertisement` that are used by different classes.

## Conclusions / Results

### Conclusion
In conclusion, this laboratory work has been a valuable learning experience in the realm of software design and architecture. Through the exploration of the SOLID principles, I have gained a deeper understanding of how to create well-structured and maintainable software projects. This knowledge has equipped me with the skills necessary to adhere to the SOLID principles, ensuring that my future projects are more robust, adaptable, and easier to maintain. 

I have learned the importance of ensuring that a class or module has only one reason to change. For example, in a previous project, I encountered a class responsible for both database access and user authentication. By applying SRP, I refactored it into separate classes, one for database access and another for authentication, improving code clarity and making future modifications easier. I have come to understand the necessity of ensuring that derived classes can be substituted for their base classes without modifying the correctness of the program. The Interface Segregation Principle has taught me to avoid creating "fat" interfaces with more methods than a client needs. 


By applying these SOLID principles in various real-world scenarios, I have not only learned how to structure projects effectively but also how to write code that is more maintainable, adaptable, and less prone to errors. This laboratory work has equipped me with a *solid* foundation in software design principles that I am eager to apply to future projects, ensuring their long-term success and sustainability which will undoubtedly benefit my career as a software engineer. 

## References
https://github.com/sspatari/tmps-labs/tree/master/Lab%231