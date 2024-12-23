from count.enumerate import find_count
from regula.your_decision import search_word, to_be_replaced_with

def search_and_replace(filename):
    """
    :param filename:
    :return:
    """
    old_word = search_word()
    new_word = to_be_replaced_with()

    with open(filename, 'r') as file:
        file_elements = file.read()

        updated_content = file_elements.replace(old_word, new_word)
        print('the word was found ', find_count(filename, old_word), ' times')

    with open(filename, 'w') as file:
        file.write(updated_content)


