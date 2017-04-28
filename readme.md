# Calculator

Basic calculator which use qml for the UI and a simple descent gradiant to compute the answer. Unlike windows calculator, this one only computes a result when the user presses enter which allows to create more complex expression.

## Grammar

E --> E "+" E
    | E "-" E
    | "-" E
    | E "*" E
    | E "/" E
    | E "%" E
    | "power(" E ")"
    | "root(" E ")"
    | "(" E ")"
    | v

in which  v  is a terminal representing identifiers and/or constants.

## Built With

* [Qt 5.8](https://www.qt.io/qt5-8/) - Framework

## Authors

* **Renaud Rwemalika** - *Initial work* - [kabinja](https://github.com/kabinja)

See also the list of [contributors](https://github.com/kabinja/calculator/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [license.md](license.md) file for details

## Acknowledgments

* Hat tip to anyone who's code was used
* Thedore Norvel for his excellent [artical](http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm) on parsing expression by recursive descent
