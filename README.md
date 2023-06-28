# CodeGeneration

Постановка задачи.

Легенда: Реализована некоторая система, которая способна генерировать код на языке С++, причем, программы только определенного вида (пример кода прилагается).

Требуется реализовать подобную генерацию программ на С# и Java, путем  расширения возможностей предложенной реализации используя фабричные подходы (абстрактная фабрика).
При реализации требуется добавить модификаторы классов и методов, которых нет в C++, но есть в C# и Java.

Реализация.

Задача реализована с применением паттерна проектирования Абстрактная фабрика.
Классы:

Unit.h - абстрактный базовый класс, определяет интерфейс для 3 классов абстрактных продуктов, которые наследуются от него: ClassUnit, MethodUnit и PrintOperatorUnit.
От ClassUnit наследуются классы конкретных продуктов ClassCpp, ClassCsharp и ClassJava.
От MethodUnit наследуются классы конкретных продуктов MethodCpp, MethodCsharp и MethodJava.
От PrintOperatorUnit наследуются классы конкретных продуктов PrintOperatorCpp, PrintOperatorCsharp и PrintOperatorJava.

CodeGeneration - класс абстрактной фабрики. От него наследуются следующие классы конкретных фабрик:
CodeGenerationCpp - для создания конкретных продуктов для языка C++: ClassCpp, MethodCpp и PrintOperatorCpp.
CodeGenerationCsharp - для создания конкретных продуктов для языка C#: ClassCsharp, MethodCsharp и PrintOperatorCsharp.
CodeGenerationJava - для создания конкретных продуктов для языка Java: ClassJava, MethodJava и PrintOperatorJava.

GenerateProgram - класс, в котором работает клиент.

![Image alt]https://github.com/anya2814/CodeGeneration/blob/master/UML1.png
