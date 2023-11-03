# Laboratory Work Nr.4

### Course: Software Design Techniques and Mechanisms
### Topic: Behavioral Design Patterns 
### Author: Iațco Sorin
----

## Theory
Behavioral design patterns are a category of design patterns that focus on the interaction and communication between objects and classes. They provide a way to organize the behavior of objects in a way that is both flexible and reusable, while separating the responsibilities of objects from the specific implementation details. Behavioral design patterns address common problems encountered in object behavior, such as how to define interactions between objects, how to control the flow of messages between objects, or how to define algorithms and policies that can be reused across different objects and classes.
## Objectives:

1. Study and understand the Behavioral Design Patterns.
2. The implemented design pattern should help to perform the tasks involved in your system.
3. The behavioral DPs can be integrated into your functionalities alongside the structural ones.
4. There should only be one client for the whole system.

## Implementation description

### Project domain
The project main idea is a car manufacturer that have a lot of dealerships and in each dealership the staff needs access 
to the vehicles information for customers or for the dealership itself. Also thy are having access to company advertisements, 
customers, factory, cars and staff. The project is structured in 5 main packages: marketing, production, staff, user, vehicle.
Each package contains classes that are related to the package name. The main idea of the project is to show how the SOLID principles are 
respected in the project and introduce all types of design patterns.

### Behavioral Patterns
#### Observer
An `Advertiser` to maintain a list of registered observers (of type `Observer`) and notify them when it wants to broadcast a message or notification (represented by a `Notification` object). Observers, such as the `ConcreteObserver`, can register with the `Advertiser`, and when the `Advertiser` calls `notifyObservers`, all registered observers will receive the notification and can take specific actions in response.

#### Strategy
The Strategy pattern is used to define a family of algorithms, encapsulate each one, and make them interchangeable. `CarInfoDisplay` is the context that utilizes different strategies (either `DetailedCarInfo` or `SummaryCarInfo`) to display car information. This approach allows to change the behavior of `CarInfoDisplay` at runtime without modifying its code. It can select and use a specific strategy to display car information, depending on the requirements or preferences.

#### Iterator
This `CarIterator` class can be used to iterate over a collection of `CarInterface` objects stored as shared pointers in a std::vector. It allows to access the elements in the collection using familiar iterator syntax, such as dereferencing with * and ->, advancing with ++, and comparing with == and !=. This makes it easier to work with complex data structures and ensures handling shared pointers correctly while iterating over them.

## Conclusions / Results

### Conclusion
In conclusion, the provided laboratory demonstrates how to apply behavioral design patterns to improve code organization, reusability, and flexibility. These patterns are valuable tools for creating maintainable and extensible software, and they help in achieving better separation of concerns and enhancing code modularity.
Each of these patterns serves a different purpose and promotes good design principles in software development.

## References
https://github.com/sspatari/tmps-labs/tree/master/Lab%234