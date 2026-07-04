<div align=center>

# 🌫️ Mist 🌫️

<img src="./Mist.png" width="300" height="300" alt="logo">

<br>

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Language: C & ASM](https://img.shields.io/badge/Language-C%20%26%20ASM-orange.svg)]()
[![Architecture: x86_64](https://img.shields.io/badge/Arch-x86__64-green.svg)]()<br>


---

[![EN](https://img.shields.io/badge/🇬🇧_EN-gray?style=flat-square)](README.md) [![RU](https://img.shields.io/badge/🇷🇺_ru-gray?style=flat-square)](README_ru.md)

---

**Mist** - это простая операционная система для х86_64 процессоров, сделанная с нуля

Этот проект сделан с целью изучения работы компьютера. Каждое исправление и улучшение приветствуется, так что _не стесняйтесь контрибьютить_.
Здесь используется MIT лицензия, поэтому можете делать с кодом все что угодно!
</div>

---
<br>

## 🤔 Что он может?
- Загружаться с собственным бутлоадером на assembly
- Контролировать физическую память с PMM
- Управлять виртуальной памятью с VMM
- Обрабатывать прерывания с IDT
- Слушать клавиатуру с драйверами клавиатуры и PIC
- Выводить что-либо на экран с помощью драйвера VGA
- Понимать некоторые команды терминала
- и т.д.

И все это сделано, используя [собственную стандартную библиотеку C](https://github.com/ImLfyz/Mist/msc/mistd)!

Так же я составил [документацию](https://github.com/ImLfyz/Mist/docs) с объяснением каждой функции в коде

<div align=center>

## Галерея

<br>

<img src="./Demo.png" alt="Demo">

---

<img src="./Error_PF.png" alt="PF Error">

---

<img src="./Error_IDT_Fail.png" alt="IDT init error">

</div>

<br>
<br>

## 🏁 Начало работы

### Зависимости:
- QEMU
- Clang
- NASM
- Make

---

Можно начать 2 путями:

1. Скомпилировать самому:
<details>

<br>

  - Скопировать репозиторий:

  ```
  git clone https://github.com/ImLfyz/Mist
  ```
  - Скомпилировать (Clang):

  ```
  cd Mist
  make
  ```
  - Запустить в QEMU:

  ```
  make run
  ```

</details>

<br>

2. Использовать Mist.img из Releases:
<details>

<br>

  - Cкопировать Mist.img:
  ```
  wget https://github.com/ImLfyz/Mist/releases/download/v0.10/Mist.img
  ```
  - Запустить в QEMU:
  ```
  qemu-system-x86_64 -drive format=raw,file=Mist.img -no-reboot
  ```

</details>

## 😰 Issues
***Mist - молодой проект, сделанный 16-летним школьником***

В нем могут быть баги и ошибки

Если вы нашли такие, можете обратиться в [issues](https://github.com/ImLfyz/Mist/issues)

Также можете делать PR с вашим кодом. Удачи!
