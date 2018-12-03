Feature: Clear
  Clear tap data from screen when clear button is pressed

  Scenario Outline: Add two numbers
    Given Application started with a beer on each tapp123
    And I have entered <input_1> into the calculator
    And I have entered <input_2> into the calculator
    When I press <button>
    Then the result should be <output> on the screen

  Examples:
    | input_1 | input_2 | button | output |
    |       1 |       2 |    add |      3 |
