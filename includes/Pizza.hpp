/*
** EPITECH PROJECT, 2019
** CPP_plazza_2018
** File description:
** Pizza.hpp
*/

#ifndef PIZZA_HPP_
    #define PIZZA_HPP_

#include "Plazza.hpp"

namespace plz
{
    typedef struct s_ingredients
    {
        bool doe;
        bool tomato;
        bool gruyere;
        bool ham;
        bool steak;
        bool eggplant;
        bool goat_cheese;
        bool mushrooms;
        bool chief_love;
    } t_ingredients;

    class Ingredients
    {
        public:
            Ingredients(t_ingredients);

            t_ingredients getIngredients() const noexcept;

    //         void setDoe();
    //         size_t getDoe() const noexcept;

    //         void setHam();
    //         size_t getHam() const noexcept;

    //         void setSteak();
    //         size_t getSteak() const noexcept;

    //         void setGotCheese();
    //         size_t getGotCheese() const noexcept;

    //         void setTomato();
    //         size_t getTomato() const noexcept;

    //         void setEggplant();
    //         size_t getEggplant() const noexcept;

    //         void setGruyere();
    //         size_t getGruyere() const noexcept;

    //         void setMushrooms();
    //         size_t getMushrooms() const noexcept;
            
    //         void setChiefLove();
    //         size_t getChiefLove() const noexcept;
    };
    class Pizza
    {
        public:
            Pizza(PizzaType, PizzaSize);

            typedef struct s_pizza
            {
                PizzaType type;
                PizzaSize size;
                t_ingredients ing;
            } t_pizza;

            PizzaType getType() const noexcept;
            std::string getName() const noexcept;
            PizzaSize getSize() const noexcept;
            t_pizza getPizza() const noexcept;

            std::array<std::tuple<PizzaType, std::string, t_ingredients, size_t>, 4> _pizzaTypes
            {
                std::make_tuple(Regina, "Regina", t_ingredients {1, 1, 1, 1, 0, 0, 0, 1, 0}, 2),
                std::make_tuple(Margarita, "Margarita", t_ingredients {1, 1, 1, 0, 0, 0, 0, 0, 0}, 1),
                std::make_tuple(Americana, "Americana", t_ingredients {1, 1, 1, 0, 1, 0, 0, 0, 0}, 2),
                std::make_tuple(Fantasia, "Fantasia", t_ingredients {1, 1, 0, 0, 0, 1, 1, 0, 1}, 4)
            };

          private:
            PizzaType _type;
            std::string _name;
            PizzaSize _size;
            t_ingredients _ing;
            size_t _time;
            t_pizza _pizza;
    };
}

#endif /* !PIZZA_HPP_ */