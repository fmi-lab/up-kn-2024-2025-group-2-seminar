# Задачи за подготовка за второ контролно

## Задача 01
Напишете функция, която приема масив от цели числа и връща указател към началото на най-дългия подмасив, елементите на който образуват аритметична прогресия. Напишете примерна програма, която показва коректността на вашата функция.

### Пример:
```
Вход:                               Изход:
0 2 4 5 2 3 -1 -5 -9 -6 -3 5        Указател към 3, понеже 3 -1 -5 -9 е най-дългият подмасив, образуващ аритметична прогресия
```

## Задача 02
Напишете функция, която по подаден масив от числа с плаваща запетая, намира такова число `k`, че всички елементи в масива, които се намират на разстояние `k` позиции едно от друго, имат една и съща разлика по модул. Ако функцията успешно намира такова число, да го изведе на стандартния изход, в противен случай да изведе `"No solution"`. Ако има няколко такива числа, да се изведе най-голямото.

### Пример:
```
Вход:                     Изход:
1.6 2.3 3 3.7 4.4         3
```

## Задача 03
Напишете функция, която приема два символни низа и проверява дали двата низа са анаграми. Два низа са анаграми, ако съдържат същите знаци, но в различен ред.

### Пример:
```
Вход:                  Изход:
listen                 true
silent
```

## Задача 04
Дадено ви е естествено число `N`, последвано от `N` букви и `N` числа. Тези букви и числа представляват кодиране - числото на позиция `i` отговаря на буквата на позиция `i`. След това ви е дадено изречение с максимална дължина от 255 символа. Това изречение може да съдържа както част от кодираните букви, така и други букви. За всяка дума в изречението намерете произведението, което се получава от разкодираните букви (ако има букви, които не са кодирани, те се игнорират). Накрая изведете сумата на всички произведения.

### Пример:
```
Вход:
6
a g l y b e
4 2 7 9 5 3
The bigger they are, the harder they fall.

Изход:
340

Обяснение:
The - 3, bigger - 60 = 5 * 2 * 2, they - 27 = 3 * 9, are - 12 = 4 * 3, harder - 12 = 4 * 3, fall - 196 = 4 * 7 * 7
```

## Задача 05
Напишете функция, която по подадена матрица от естествени числа и естествено число `k` намира най-големия брой съседни елементи в матрицата, които имат един и същ най-голям общ делител с `k`.

### Пример:
```
Вход:                       Изход:
k: 54                       5
24 36 32 72
68 18 44 126
92 78 90 144
84 21 36 0
```