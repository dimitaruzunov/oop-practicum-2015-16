# Упражнение 1

## Задача 0. Минимален и максимален елемент

Да се напише функция, извеждаща минималния и максималния по абсолютна стойност елемент на:

- масив от цели числа
- матрица от цели числа

## Задача 1. Калкулатор на матрици

Да се реализира калкулатор за работа с матрици, поддържащ следните операции:

- `void readMatrix(int matrix[][100], int m, int n);` - Прочитане на матрица от цели числа с размерност `m` x `n` от стандартния вход.

- `void printMatrix(int matrix[][100], int m, int n);` - Извеждане на матрица от цели числа с размерност `m` x `n` на стандартния изход, като всеки ред от матрицата да бъде изведен на нов ред.

- `void sumMatrices(int a[][100], int b[][100], int c[][100], int m, int n);` - събиране на матриците `a` и `b` с размерност `m` x `n`, като `c` (`m` x `n`) е матрицата, получена в резултат от събирането. Да се напише функция `void testSum();`, която тества функцията.

- `void multiplyMatrices(int a[][100], int b[][100], int c[][100], int m, int n, int k);` - Умножение на матриците `a` и `b` с размерности съответно `m` x `n` и `n` x `k`, като `c` (`m` x `k`) е матрицата, получена в резултат от умножението. Да се напише функция `void testMultiplication();`, която тества функцията.

Да бъде реализирано меню за работа с калкулатора (в менюто да бъдат включени и функциите за тестване).


## Задача 2. Степенуване

По дадено естествено число N > 1 да се намерят последните 4 цифри на числото, повдигнато на степен 10^17.
Не е нужно да се извеждат водещите нули.

Подзадачи, за решаване на задачата:

- Да се напише рекурсивна функция, повдигаща число на степен.
- Да се напише итеративна функция, повдигаща число на степен.
- Да се напише рекурсивна функция, повдигаща число на степен, използваща алгоритъма за бързо степенуване.
- Да се модифицират двете, написани функции, да изчисляват само последните 4 цифри на числото.
- Да се напише функция, която сравнява резултатите от функциите.
- Да се реализира меню за извикване на всички функции.


## Задача 3. Лабиринт

Даден е лабиринт като матрица от символи:

	.#.##
	o#.#.
	.#...
	.#$#.
	.###.
	.....
	.####

Стените са отбелязани с '#', началната позиция е 'о', а позициите, по които може да се минава са отбелязани с '.'. 
В лабиринта има съкровище, отбелязано с '$'. 

- Да се напише функция, която въвежда лабиринта.

- Да се напише функция, която извежда лабиринта.

- Да се напише функция, която проверява дали може да се достигне до съкровището от дадената позиция 
и извежда позицията на съкровището, ако то бъде намерено.

- Бонус: Да се извеждат и броя на стъпките за достигане на съкровището.
