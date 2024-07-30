import tkinter as tk
import tkinter.messagebox as mb
import lib

a = list()

def check_input():
    try:
        if (int(arr_size_entry.get()) <= 0):
            mb.showerror(title="Ошибка", message="Размер должен быть положительным целым числом")
    except ValueError:
        mb.showerror(title="Ошибка", message="Размер должен быть положительным целым числом")

    try:
        els = list(arr_entry.get().split())
        if (len(els) != int(arr_size_entry.get())):
            mb.showerror(title="Ошибка", message="Размер должен быть равен количеству элементов")
        else:
            for i in range(len(els)):
                a.append(int(els[i]))
    except ValueError:
        mb.showerror(title="Ошибка", message="Элемент массива должен быть целым числом")

def shift_logic():
    a.clear()
    check_input()
    try:
        shift_val = int(shift_entry.get())
        res_shift = lib.shift(a, shift_val)
        if (res_shift[0] != 0):
            mb.showerror(title="Ошибка", message="Возникла ошибка сдвига")
        else:
            arr_entry.delete(0, len(arr_entry.get()))
            arr_entry.insert(0, ' '.join(map(str, res_shift[1])))
    except ValueError:
        mb.showerror(title="Ошибка", message="Сдвиг должен быть целым числом")

def filter_logic_1():
    a.clear()
    check_input()
    res_filt_1 = lib.filter_1(a)
    if (res_filt_1[0] != 0):
        mb.showerror(title="Ошибка", message="Возникла ошибка фильтрации")
    else:
        rule_1.delete(0, len(rule_1.get()))
        rule_1.insert(0, ' '.join(map(str, res_filt_1[1])))

def filter_logic_2():
    a.clear()
    check_input()
    res_filt_2 = lib.filter_2(a)
    if (res_filt_2[0] != 0):
        mb.showerror(title="Ошибка", message="Возникла ошибка фильтрации")
    else:
        rule_2.delete(0, len(rule_2.get()))
        rule_2.insert(0, ' '.join(map(str, res_filt_2[1])))


root = tk.Tk()
root.title("ЛР12")

tk.Label(text="Введите размер массива:", font="Arial 20").grid(column=0, row=0, columnspan=2)
arr_size_entry = tk.Entry(font="Arial 20")
arr_size_entry.grid(column=2, row=0)

tk.Label(text="Введите элементы массива:", font="Arial 20").grid(column=0, row=2, columnspan=2)
arr_entry = tk.Entry(font="Arial 20")
arr_entry.grid(column=2, row=2)

tk.Label(text="Сдвинуть на:", font="Arial 20").grid(column=0, row=4)
shift_entry = tk.Entry(font="Arial 20")
shift_entry.grid(column=1, row=4)
tk.Button(text="Циклический сдвиг", width=40, height=2, command=lambda: shift_logic()).grid(column=2, row=4)

tk.Label(text="Фильтр 1:", font="Arial 20").grid(column=0, row=6)
rule_1 = tk.Entry(font="Arial 20")
rule_1.grid(column=1, row=6, columnspan=1)
tk.Button(text="Найти полные квадраты v1", width=40, height=2, command=lambda: filter_logic_1()).grid(column=2, row=6)

tk.Label(text="Фильтр 2:", font="Arial 20").grid(column=0, row=8)
rule_2 = tk.Entry(font="Arial 20")
rule_2.grid(column=1, row=8, columnspan=1)
tk.Button(text="Найти полные квадраты v2", width=40, height=2, command=lambda: filter_logic_2()).grid(column=2, row=8)

root.mainloop()
