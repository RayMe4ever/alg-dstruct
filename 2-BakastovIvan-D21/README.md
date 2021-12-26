Гамильтонов путь
Условие
Гамильтонов путь (или гамильтонова цепь) — путь (цепь), содержащий каждую вершину
графа ровно один раз. Гамильтонов путь, начальная и конечная вершины которого
совпадают, называется гамильтоновым циклом.
Зада граф G  (V, E). Определите, существует ли гамильтонов путь в этом графе.
Исходные данные
В текстовом файле input.txt храниться граф заданный списком смежности. В первой cтроке
указано количество вершин в графе V  1000, в последующих строках содержаться
списки номеров смежных вершин. Вершины нумеруются начиная с 1. Выведите в
текстовый файл output.txt номера вершин в том порядке, в котором они встречаются в
гамильтоновом пути на заданном графе. Если такого пути нет, выведите 0.
Пример
В примере рассмотрен граф с тремя вершинами, образующих треугольник
input.txt output.txt

3
2 3
1 3
1 2

1 2 3