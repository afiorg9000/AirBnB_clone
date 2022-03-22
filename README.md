0x00. AirBnB clone - The console
================================

![Image of Holberton B&B Logo](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-higher-level_programming+/263/HBTN-hbnb-Final.png)

## Welcome to the AirBnB clone project!

### First step and goal of this repository: Write a command interpreter to manage your AirBnB objects.
This is the first step towards building the first full web application: the AirBnB clone. This first step is very important because we will use what we build during this project with all other following projects: HTML/CSS templating, database storage, API, front-end integration…

## Execution

The hbnb command interpreter should work like this in interactive mode:

```
$ ./console.py
(hbnb) help

Documented commands (type help <topic>):
========================================
EOF  help  quit

(hbnb)
(hbnb)
(hbnb) quit
$
```

But also in non-interactive mode: (like the Shell project in C):

```
$ echo "help" | ./console.py
(hbnb)

Documented commands (type help <topic>):
========================================
EOF  help  quit
(hbnb)
$
$ cat test_help
help
$
$ cat test_help | ./console.py
(hbnb)

Documented commands (type help <topic>):
========================================
EOF  help  quit
(hbnb)
$
```

All tests should also pass in non-interactive mode: ``` $ echo "python3 -m unittest discover tests" | bash ```

## Airbnb files structure

|File|Description
|---|---
|[console.py](./console.py)|command interpreter to manage your AirBnB objects: Create a new object (ex: a new User or a new Place)
||Retrieve an object from a file, a database, etc… 
||Do operations on objects
||Update attributes of an object
||Destroy an object
|[models](./models)|directory of all the classes
|[tests](./tests)|directory of console test and class tests

## How to run the console

You can use```./console.py``` to run the command interpreter in your terminal and use the commands listed below.

```
guillaume@ubuntu:~/AirBnB$ ./console.py
(hbnb) help

Documented commands (type help <topic>):
========================================
EOF  help  quit

(hbnb)
(hbnb) help quit
Quit command to exit the program

(hbnb)
(hbnb)
(hbnb) quit
guillaume@ubuntu:~/AirBnB$
```

|Commands|Format|Instance form|Description
|---|---|---|---
|quit|```quit```||Exit the program
|empty line|``` ```||passes an empty prompt
|create|```create <class name>```|| create an instance of the class
|show|```show <class name> <id number>```|```<class name>.show(<id>)```|Prints the string representation of an instance based on the class name and id
|destroy|```destroy <class name> <id number>```|```<class name>.destroy(<id>)```|Deletes an instance based on the class name and id (save the change into the JSON file)
|all|```all``` or ```all <class name>```|```<class name>.all()```|Prints all string representation of all instances based or not on the class name
|update|```update <class name> <id number> <attribute to update> "<new value of attribute>"```|simple form:```<class name>.update(<id>, <attribute name>, <attribute value>)``` update more than 1 attribute(using dictionaries): ```<class name>.update(<id>, <dictionary representation>)```|Updates an instance based on the class name and id by adding or updating attribute (save the change into the JSON file). If there are more commands, the command interpreter will only count the first attribute with its value

|classes
|---
|BaseModel|```BaseModel```
|User|```User```
|Place|```Place```
|State|```State```
|City|```City```
|Amenity|```Amenity```
|Review|```Review```
|User|```User```

#### Examples:

* help:

```
(hbnb) help

Documented commands (type help <topic>):
========================================
EOF  help  quit

```

* quit:

```
(hbnb) quit 
vagrant@ubuntu:~/AirBnB$
```

* create:

```
(hbnb) create BaseModel
2dd6ef5c-467c-4f82-9521-a772ea7d84e9
(hbnb) create User
35dd5991-c54f-4e33-a4c4-2be5219cc15e
```

* all:

```
(hbnb) all BaseModel
["[BaseModel] (49faff9a-6318-451f-87b6-910505c55907) {'created_at': datetime.datetime(2017, 10, 2, 3, 10, 25, 903293), 'id': '49faff9a-6318-451f-87b6-910505c55907', 'updated_at': datetime.datetime(2017, 10, 2, 3, 10, 25, 903300)}"]
```

* show:

```
(hbnb) show BaseModel 49faff9a-6318-451f-87b6-910505c55907
[BaseModel] (49faff9a-6318-451f-87b6-910505c55907) {'created_at': datetime.datetime(2017, 10, 2, 3, 10, 25, 903293), 'id': '49faff9a-6318-451f-87b6-910505c55907', 'updated_at': datetime.datetime(2017, 10, 2, 3, 10, 25, 903300)}
```

* destroy:

```
(hbnb) destroy
** class name missing **
```

* update:

```
(hbnb) show BaseModel 49faff9a-6318-451f-87b6-910505c55907
[BaseModel] (49faff9a-6318-451f-87b6-910505c55907) {'created_at': datetime.datetime(2017, 10, 2, 3, 10, 25, 903293), 'id': '49faff9a-6318-451f-87b6-910505c55907', 'updated_at': datetime.datetime(2017, 10, 2, 3, 10, 25, 903300)}
(hbnb) update BaseModel 49faff9a-6318-451f-87b6-910505c55907 first_name "Betty"
(hbnb) show BaseModel 49faff9a-6318-451f-87b6-910505c55907
[BaseModel] (49faff9a-6318-451f-87b6-910505c55907) {'first_name': 'Betty', 'id': '49faff9a-6318-451f-87b6-910505c55907', 'created_at': datetime.datetime(2017, 10, 2, 3, 10, 25, 903293), 'updated_at': datetime.datetime(2017, 10, 2, 3, 11, 3, 49401)}
```

* all or all BaseModel:
```
(hbnb) create User
35dd5991-c54f-4e33-a4c4-2be5219cc15e
(hbnb) create BaseModel
2c181221-b41f-47f9-bf2a-9e7bc53126a1
(hbnb) all BaseModel
["[BaseModel] (2c181221-b41f-47f9-bf2a-9e7bc53126a1) {'id': '2c181221-b41f-47f9-bf2a-9e7bc53126a1', 'created_at': datetime.datetime(2021, 7, 1, 4, 46, 34, 306736), 'updated_at': datetime.datetime(2021, 7, 1, 4, 46, 34, 306804)}", "[User] (35dd5991-c54f-4e33-a4c4-2be5219cc15e) {'id': '35dd5991-c54f-4e33-a4c4-2be5219cc15e', 'created_at': datetime.datetime(2021, 7, 1, 4, 46, 0, 151113), 'updated_at': datetime.datetime(2021, 7, 1, 4, 46, 0, 151209)}"]
(hbnb) all
["[BaseModel] (2c181221-b41f-47f9-bf2a-9e7bc53126a1) {'id': '2c181221-b41f-47f9-bf2a-9e7bc53126a1', 'created_at': datetime.datetime(2021, 7, 1, 4, 46, 34, 306736), 'updated_at': datetime.datetime(2021, 7, 1, 4, 46, 34, 306804)}", "[User] (35dd5991-c54f-4e33-a4c4-2be5219cc15e) {'id': '35dd5991-c54f-4e33-a4c4-2be5219cc15e', 'created_at': datetime.datetime(2021, 7, 1, 4, 46, 0, 151113), 'updated_at': datetime.datetime(2021, 7, 1, 4, 46, 0, 151209)}"]
(hbnb) all User
["[User] (35dd5991-c54f-4e33-a4c4-2be5219cc15e) {'id': '35dd5991-c54f-4e33-a4c4-2be5219cc15e', 'created_at': datetime.datetime(2021, 7, 1, 4, 46, 0, 151113), 'updated_at': datetime.datetime(2021, 7, 1, 4, 46, 0, 151209)}"]
(hbnb) 
```

#### Instance mode:

* `<class name>.all() `:

```
hbnb) User.all()
["[User] (35dd5991-c54f-4e33-a4c4-2be5219cc15e) {'id': '35dd5991-c54f-4e33-a4c4-2be5219cc15e', 'created_at': datetime.datetime(2021, 7, 1, 4, 46, 0, 151113), 'updated_at': datetime.datetime(2021, 7, 1, 4, 46, 0, 151209)}", "[User] (03be30e8-d686-4b4f-bdb0-66180bb76c62) {'id': '03be30e8-d686-4b4f-bdb0-66180bb76c62', 'created_at': datetime.datetime(2021, 7, 1, 4, 48, 2, 274519), 'updated_at': datetime.datetime(2021, 7, 1, 4, 48, 2, 274584)}"]
```

* ```<class name>.show(<id>)```:

```
(hbnb) User.show("35dd5991-c54f-4e33-a4c4-2be5219cc15e")
[User] (35dd5991-c54f-4e33-a4c4-2be5219cc15e) {'id': '35dd5991-c54f-4e33-a4c4-2be5219cc15e', 'created_at': datetime.datetime(2021, 7, 1, 4, 46, 0, 151113), 'updated_at': datetime.datetime(2021, 7, 1, 4, 46, 0, 151209)}
(hbnb)
```

* ```<class name>.destroy(<id>)```:

```
(hbnb) User.count()
2
(hbnb) User.destroy("35dd5991-c54f-4e33-a4c4-2be5219cc15e")
(hbnb) User.count()
1
(hbnb)
```

* update

```
(hbnb) User.show("03be30e8-d686-4b4f-bdb0-66180bb76c62")[User] (03be30e8-d686-4b4f-bdb0-66180bb76c62) {'id': '03be30e8-d686-4b4f-bdb0-66180bb76c62', 'created_at': datetime.datetime(2021, 7, 1, 4, 48, 2, 274519), 'updated_at': datetime.datetime(2021, 7, 1, 4, 48, 2, 274584)}
(hbnb) User.update("03be30e8-d686-4b4f-bdb0-66180bb76c62", "first_name", "John")
(hbnb) User.show("03be30e8-d686-4b4f-bdb0-66180bb76c62")[User] (03be30e8-d686-4b4f-bdb0-66180bb76c62) {'updated_at': datetime.datetime(2021, 7, 1, 4, 53, 12, 110537), 'id': '03be30e8-d686-4b4f-bdb0-66180bb76c62', 'first_name': '"John"', 'created_at': datetime.datetime(2021, 7, 1, 4, 48, 2, 274519)}
```


## Models file Structure

|File|Description|Recommendations
|---|---|---
|[engine](./models/engine)|directory of Store first object|The first way you will see here is to save these objects to a file with dictionaries: ```<class 'BaseModel'> -> to_dict() -> <class 'dict'> -> <class 'BaseModel'>```
|[__init__.py](./models/engine/__init__.py)|initialization code for the package|files are required to make Python treat the directories as containing packages; this is done to prevent directories with a common name
|[amenity.py](./models/engine/amenity.py)|Amenity class| Inherits from BaseModel and contains specific public attributes
|[base_model.py](./models/engine/base_model.py)| Base Model class|  Defines all common attributes/methods for other classes sach as id, datetime
|[city.py](./models/engine/city.py)|City Class| Inherits from BaseModel and contains specific public attributes
|[place.py](./models/engine/place.py)|Place Class| Inherits from BaseModel and contains specific public attributes
|[review.py](./models/engine/review.py)|Review Class| Inherits from BaseModel and contains specific public attributes
|[state.py](./models/engine/state.py)|State Class| Inherits from BaseModel and contains specific public attributes
|[user.py](./models/engine/user.py)|User Class| Inherits from BaseModel and contains specific public attributes
