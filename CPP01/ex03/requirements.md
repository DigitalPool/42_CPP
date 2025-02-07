Below is a detailed explanation of what the **Unnecessary Violence** (Exercise 03) is asking you to do and all the key concepts you need to understand in order to implement it in C++. The exercise focuses on classes, object composition, references, pointers, and how C++ handles ownership and optionality of member variables.

---

## 1. Overview of the Exercise

You need to create:

1. A **Weapon** class.
2. Two human classes: **HumanA** and **HumanB**.

Each human has a **name** and a means of attacking via a **Weapon**. The biggest difference between **HumanA** and **HumanB**:

- **HumanA** is always armed. That means you **must** pass a `Weapon&` in the constructor of **HumanA**.
- **HumanB** **may or may not** be armed at any given time. Hence, it starts without a weapon and can later get one via a setter.

### Files to Turn In

- `Makefile`
- `main.cpp`
- `Weapon.{h, hpp}`, `Weapon.cpp`
- `HumanA.{h, hpp}`, `HumanA.cpp`
- `HumanB.{h, hpp}`, `HumanB.cpp`

*(The exercise instructions may list either `.hpp` or `.h` for the header files. Just pick one approach and be consistent.)*

---

## 2. The Weapon Class

**Requirements:**

1. A **private** attribute `type` (a `std::string`).
2. A `getType()` member function that returns a **const reference** to `type`.
3. A `setType()` member function that sets `type` using the parameter passed.

### Example Implementation

**Weapon.hpp**:
```cpp
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;

public:
    // Constructor
    Weapon(const std::string& type);

    // Getter: returns a const reference to the internal type string
    const std::string& getType() const;

    // Setter: sets the internal type string
    void setType(const std::string& newType);
};

#endif
```

**Weapon.cpp**:
```cpp
#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) {}

const std::string& Weapon::getType() const {
    return this->type;
}

void Weapon::setType(const std::string& newType) {
    this->type = newType;
}
```

**Key Points**:
- The constructor takes a `const std::string&` to avoid unnecessary string copies.
- `getType()` returns a `const std::string&`, which allows you to **read** the weapon type without copying it or being able to modify the internal string directly.
- `setType()` modifies the weapon’s type.

---

## 3. The HumanA Class

**Requirements**:
1. Has a **name** (`std::string`).
2. Has a **Weapon** that is always valid (armed from the start).
3. Has an `attack()` function that prints:
   ```
   <name> attacks with their <weapon type>
   ```
4. The constructor for **HumanA** takes a `std::string name` and a `Weapon& weapon` as parameters.

### Example Implementation

**HumanA.hpp**:
```cpp
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon& weapon;  // reference to a Weapon

public:
    HumanA(const std::string& name, Weapon& weapon);

    void attack() const;
};

#endif
```

**HumanA.cpp**:
```cpp
#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
    : name(name), weapon(weapon) {
}

void HumanA::attack() const {
    std::cout << this->name << " attacks with their "
              << this->weapon.getType() << std::endl;
}
```

**Key Points**:
- We store a **reference** to `Weapon`, because `HumanA` is always armed and must always have a valid weapon.
- References **must** be initialized upon creation. You cannot later change which `Weapon` a `HumanA` is referencing.
- The `attack()` function fetches the current weapon type from `weapon.getType()`.

---

## 4. The HumanB Class

**Requirements**:
1. Has a **name** (`std::string`).
2. Has a **Weapon** but not necessarily from the start. Hence, it may initially be **unarmed**.
3. Has an `attack()` function that prints:
   ```
   <name> attacks with their <weapon type>
   ```
   If the human has no weapon, you can decide how to handle it (e.g., print something like “has no weapon” or skip).
4. The constructor for **HumanB** takes only the `std::string name`. It does **not** take a `Weapon` reference or pointer in the constructor.
5. A `setWeapon()` function that allows the user to provide a weapon at any later point in time.

### Example Implementation

**HumanB.hpp**:
```cpp
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;  // pointer to a Weapon (can be null)

public:
    HumanB(const std::string& name);

    // sets the weapon if needed
    void setWeapon(Weapon& weapon);

    void attack() const;
};

#endif
```

**HumanB.cpp**:
```cpp
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name)
    : name(name), weapon(nullptr) {
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;  // store address of the weapon
}

void HumanB::attack() const {
    if (this->weapon) {
        std::cout << this->name << " attacks with their "
                  << this->weapon->getType() << std::endl;
    } else {
        std::cout << this->name << " has no weapon to attack with!" << std::endl;
    }
}
```

**Key Points**:
- `weapon` is a pointer (type `Weapon*`), which can be `nullptr` initially to indicate “no weapon.”
- `setWeapon()` accepts a `Weapon&`, but internally we store the address of that `Weapon` in `weapon`.
- `attack()` checks if `weapon` is **not** `nullptr` before trying to use it.

---

## 5. The `main.cpp` Provided in the Exercise

The exercise provides a snippet that you can use to test your classes. If your classes are implemented correctly, you’ll see the expected output in the console:

```cpp
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }

    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    return 0;
}
```

### What You Should See

1. **First block (HumanA)**:
   - Bob attacks with "crude spiked club".
   - Weapon type changes to "some other type of club".
   - Bob attacks again with "some other type of club".

2. **Second block (HumanB)**:
   - Jim initially sets his weapon to the “crude spiked club”.
   - Jim attacks with "crude spiked club".
   - Weapon type changes to "some other type of club".
   - Jim attacks again with "some other type of club".

---

## 6. Dealing with Memory Leaks

Since you are **not** dynamically allocating memory with `new` in this exercise, there should be no memory leaks if you keep everything on the stack:

- `Weapon` objects are allocated locally in `main()`.
- `HumanA` references a local `Weapon` (stack-allocated).
- `HumanB` points to a local `Weapon` (also stack-allocated), but doesn’t manage (allocate or delete) that memory.

As long as you don’t use `new` without corresponding `delete`, you’ll be fine. This exercise doesn’t require dynamic allocation at all.

---

## 7. When to Use References vs. Pointers

The prompt asks:
> In which case do you think it would be best to use a pointer to `Weapon`?
> And a reference to `Weapon`? Why?

### References
- **HumanA** uses a reference because it is **always** guaranteed to have a weapon.
- Once you bind a reference in the constructor, that reference cannot be reseated to refer to another object. This is ideal if you never want a `HumanA` to exist without a weapon or to switch to a different weapon object.
- This enforces that a valid `Weapon` must exist throughout the lifetime of `HumanA`.

### Pointers
- **HumanB** uses a pointer because it may or may not have a weapon at any moment.
- A pointer can be `nullptr`, indicating the absence of a weapon.
- You can also easily change the pointer to point to a different `Weapon` if you want to.
- This is ideal for optional relationships: `HumanB` might go unarmed for a while, then pick up a weapon.

---

## 8. Example Makefile

Below is an example of how your **Makefile** might look:

```makefile
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yourname <yourname@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 00:00:00 by yourname         #+#    #+#              #
#    Updated: 2023/01/01 00:00:00 by yourname        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
      Weapon.cpp \
      HumanA.cpp \
      HumanB.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
```

**Key Points**:
- `SRC` lists all the `.cpp` files in the project.
- `OBJ` is generated by replacing `.cpp` with `.o`.
- `$(NAME)` depends on the `.o` files; when linking, it produces the executable.
- `clean` and `fclean` remove object files and the final executable, respectively.
- `re` rebuilds everything from scratch.

---

## 9. Putting It All Together

If you’ve done everything correctly:

1. Compile your project by running `make`.
2. An executable named `ex03` (or whatever you chose) will be created.
3. Run `./ex03`.
4. You should see:

```
Bob attacks with their crude spiked club
Bob attacks with their some other type of club
Jim attacks with their crude spiked club
Jim attacks with their some other type of club
```

*(Your exact output formatting may differ, but the essential text should match.)*

---

## 10. Final Thoughts

- This exercise teaches you how to use **references** and **pointers** in practical scenarios.
- You learn about **object composition** (a `HumanA`/`HumanB` **has-a** `Weapon`).
- You also get a better understanding of how to manage optional vs. mandatory object relationships in C++.
- No advanced memory management is required here, but keep an eye out for potential segmentation faults if you forget to handle the case where `HumanB` might not have a weapon.

### Good luck, and happy coding!
