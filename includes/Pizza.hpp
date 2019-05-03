/*
** EPITECH PROJECT, 2019
** CPP_plazza_2018
** File description:
** Pizza.hpp
*/

#ifndef PIZZA_HPP_
    #define PIZZA_HPP_

#include <memory>
#include "Plazza.hpp"

namespace plz
{
    typedef struct s_ingredients
    {
        size_t doe;
        size_t tomato;
        size_t gruyere;
        size_t ham;
        size_t steak;
        size_t eggplant;
        size_t goat_cheese;
        size_t mushrooms;
        size_t chief_love;

        friend std::ostream &operator<<(std::ostream &os, s_ingredients const &a)
        {
            return os
                << "chief_love: " << a.chief_love << std::endl
                << "doe: " << a.doe << std::endl
                << "eggplant: " << a.eggplant << std::endl
                << "goat_cheese: " << a.goat_cheese << std::endl
                << "gruyere: " << a.gruyere << std::endl
                << "ham: " << a.ham << std::endl
                << "mushrooms: " << a.mushrooms << std::endl
                << "steak: " << a.steak << std::endl
                << "tomato: " << a.tomato << std::endl;
        }
    } t_ingredients;

    class Ingredients
    {
        public:
            void updateIngredients(std::shared_ptr<t_ingredients>, t_ingredients);
            void restock(std::shared_ptr<t_ingredients>, size_t);
            bool checkIngredients(t_ingredients, t_ingredients);
            bool checkIsEmpty(std::shared_ptr<t_ingredients>);
    };
    class Pizza
    {
        public:
            Pizza(PizzaType);//, PizzaSize);

            typedef struct s_pizza
            {
                PizzaType type;
                PizzaSize size;
                t_ingredients ing;
            } t_pizza;

            PizzaType getType() const noexcept;
            std::string getName() const noexcept;
            PizzaSize getSize() const noexcept;
            t_ingredients getIngredients() const noexcept;
            size_t getTime() const noexcept;
            t_pizza getPizza() const noexcept;

            std::array<std::tuple<PizzaType, std::string, t_ingredients, size_t>, 5> _pizzaTypes{
                std::make_tuple(Regina, "Regina", t_ingredients{1, 1, 1, 1, 0, 0, 0, 1, 0}, 2),
                std::make_tuple(Margarita, "Margarita", t_ingredients{1, 1, 1, 0, 0, 0, 0, 0, 0}, 1),
                std::make_tuple(Americana, "Americana", t_ingredients{1, 1, 1, 0, 1, 0, 0, 0, 0}, 2),
                std::make_tuple(Fantasia, "Fantasia", t_ingredients{1, 1, 0, 0, 0, 1, 1, 0, 1}, 4)
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