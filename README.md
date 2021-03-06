# some-cpp-labs
Some labs I've done during my "object-oriented programming" c++ course in SPbPU


Правила:
--------

* Каждая работа находится в каталоге, имя которого
  представляет собой объединение заглавной латинской буквы,
  обозначающей семестр ("A" или "B") и номера работы, например,
  "/A1" для первой работы первого семестра.

* Все работы должны быть написаны в рамках стандарта C++ 14.

* Каждая работа должна быть выполнена в отдельном Merge
  Request.

* Каждый коммит должен содержать логически единое изменение и
  обладать комментарием, из которого понятно что и зачем
  было сделано.

* На проекте используется (использовалась) Continuous Integration (CI),
  соответственно, сборка и тестирование выполняются автоматически.
  Коммиты, не прошедшие CI (с ошибкой или пропустившие CI) не
  принимаются. Результаты тестирования доступны в виде архива
  артефактов сборки и могут быть получены по ссылке "Download
  acceptance artifacts" Web UI, указанной либо в коммите, либо в CI
  pipeline.

Сборка работ:
-------------

Для сборки и запуска работ присутствует Makefile для
[GNU Make](https://www.gnu.org/software/make/). Все работы
автоматически обнаруживаются и могут быть построены с использованием
нескольких целей.

Идентификатором каждой работы является строка
`lastname.firstname/labnumber`, на которую в дальнейшем ссылаются при
помощи `labid`.

Все исходные тексты в каждой работе идентифицируются по расширению
"cpp". Обнаруженные исходные тексты делятся на группы:

* Исходные тексты работы: все файлы, имена которых _не_ начинаются с
  "test-".

* Исходные тексты тестов: все файлы, исключая файл "main.cpp".

Как видно, файл "main.cpp" стоит особняком: его назначение - функция
`main()` выполненной работы.

Makefile автоматически строит программу для каждой работы. Так как имя
программы в общем случае неизвестно, специальная цель выполняет запуск
построенной программы с передачей параметров.

Общие файлы для нескольких работ должны размещаться в подкаталоге
"common" своего каталога. Они будут автоматически добавлены при сборке
работы. Внутри каталога "common" допустимо создавать подкаталоги для
организации файлов.

Поддерживаемые цели:

* `build-labid`: построение лабораторной работы, например

        $ make build-ivanov.ivan/2

* `run-labid`: запуск построенной программы, например

        $ make run-ivanov.ivan/2

    Для передачи дополнительных параметров используется переменная
    `ARGS` (при помощи GNU Make):

        $ make run-ivanov.ivan/1 ARGS="1 ascending"

    или (c использованием Bourne Shell):

        $ ARGS="1 ascending" make run-ivanov.ivan/1

    или (Bourne Shell, с сохранением в окружении процесса):

        $ export ARGS="1 ascending"
        $ make run-ivanov.ivan/1

* `test-labid`: сборка и запуск тестов работы:

        $ make test-ivanov.ivan/3

    Переменная `TEST_ARGS` используется для передачи параметров тестам
    аналогично `ARGS`.

* `labs`: список всех лабораторных в проекте.

Дополнительной возможностью является запуск динамического анализатора
[Valgrind](http://valgrind.org) для запускаемых программ. Для этого
необходимо указать в переменной `VALGRIND` параметры анализатора так,
как это делается для `ARGS`/`TEST_ARGS`.

Boost
=====

Библиотека [Boost](http://boost.org) может находиться в нестандартном
месте. Для того, чтобы указать его, в корне проекта необходимо
разместить файл `.boost_location`, состоящий из одной строки с путем к
корню библиотеки.

> Путь не должен содержать пробельные символы.


