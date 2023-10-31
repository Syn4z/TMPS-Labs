# Laboratory Work Nr.3

### Course: Software Design Techniques and Mechanisms
### Topic: Structural Design Patterns 
### Author: Iațco Sorin
----

## Theory
Structural design patterns are a category of design patterns that focus on the composition of classes and objects to form larger structures and systems. They provide a way to organize objects and classes in a way that is both flexible and efficient, while allowing for the reuse and modification of existing code. Structural design patterns address common problems encountered in the composition of classes and objects, such as how to create new objects that inherit functionality from existing objects, how to create objects that share functionality without duplicating code, or how to define relationships between objects in a flexible and extensible way.
## Objectives:

1. Study and understand the Structural Design Patterns.
2. As a continuation of the previous laboratory work, think about the functionalities that your system will need to provide to the user.
3. Implement some additional functionalities, or create a new project using structural design patterns.


## Implementation description

### Project domain
The project main idea is a car manufacturer that have a lot of dealerships and in each dealership the staff needs acces 
to the vehicles information for customers or for the dealership itself. Also thy are having acces to company advertisements, 
customers, factory and staff. The project is structured in 5 main packages: assembly-line, carManufacturing, marketing, personnel and user.
Each package contains classes that are related to the package name. The main idea of the project is to show how the SOLID principles are 
respected in the project and introduce all types of design patterns.

### Structural Patterns
#### Decorator
`TunedCarDecorator` is a subclass that extends or decorates a car object implementing the `CarInterface` interface.
The constructor takes a `Car` object as an argument, representing the car to be decorated.
Is overridden methods from CarInterface, which appends `Tuned` to the features of the decorated car. It returns the combined features.

`CarDecorator` is an abstract class that also implements the `CarInterface` interface. It serves as the base class for various car decorators, allowing you to add new functionalities to cars without modifying their base class.
CarDecorator contains a set of methods that delegate the functionality to the wrapped car object. In the code, methods like getBrand, getModel, getYear, getFeatures, and so on, are implemented by forwarding the calls to the wrapped car object (the `car_` member variable).

#### Bridge
The Bridge pattern allows to combine different types of civil cars with different car actions independently. For example, you can create an `OffroadCar` with either `SUVActions` or `SedanActions`, and the behavior of the car is determined by the action implementation while keeping the car type separate. This separation of concerns is the core principle of the Bridge design pattern.

#### Composite
Composite allows to create a hierarchy of employees, where a `Supervisor` can have multiple subordinates, including other `Supervisor` objects and `Worker` objects. The Composite pattern allows you to treat individual employees and groups of employees (supervisors with subordinates) uniformly through a common interface `Employee`, making it easy to manage and work with hierarchical structures of employees.

#### Facade
With the `EngineFacade`, you can start and stop the car's engine without needing to know the details of how the subsystems work. The facade hides the complexity of the subsystems and provides a simple and unified interface for controlling the car's engine. This makes it easier to use and maintain, especially when dealing with complex systems like a car engine.

## Conclusions / Results

### Conclusion
In conclusion, these design patterns are valuable tools for improving software design, promoting code maintainability, and enhancing the flexibility and modularity of a system. By applying these patterns appropriately, we can create more robust and scalable software solutions that are easier to understand and extend. However, it's important to remember that design patterns should be chosen based on the specific requirements and constraints of a given project, as not all patterns are suitable for every situation.

## References
https://github.com/sspatari/tmps-labs/tree/master/Lab%233