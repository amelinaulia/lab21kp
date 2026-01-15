#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct router {
    int manufacturer_code;          // код производителя (1-D-Link, 2-TP-Link, 3-Asus, 4-ZyXEL, 5-Netgear, 6-Tenda)
    double wired_speed;             // скорость по проводу (Мбит/с) - ИЗМЕНЕНО на DOUBLE
    int wifi_standard_code;         // код стандарта Wi-Fi (1-802.11n, 2-802.11ac, 3-802.11ax)
    int dual_band;                  // работа в двух диапазонах (0/1) - INT
    long float type_code;           // код типа роутера (1-домашний, 2-офисный, 3-игровой, 4-промышленный) - ИЗМЕНЕНО на LONG FLOAT
    float lan_ports;                // количество LAN портов - FLOAT
    int gaming;                     // подходит для онлайн-игр (0/1) - INT
    int vpn_support;                // функции VPN (0/1) - INT
    int mesh_support;               // поддержка MESH (0/1)
    long double max_wifi_speed;     // максимальная скорость Wi-Fi (Мбит/с) - LONG DOUBLE
    int usb_port;                   // наличие USB разъема (0/1)
    int mobile_internet;            // мобильный выход в интернет (0/1)
};
typedef struct router router;

/* ===== ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ===== */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ===== ФУНКЦИИ ПРЕОБРАЗОВАНИЯ ===== */
const char* get_manufacturer_name(int code) {
    switch (code) {
    case 1: return "D-Link";
    case 2: return "TP-Link";
    case 3: return "Asus";
    case 4: return "ZyXEL";
    case 5: return "Netgear";
    case 6: return "Tenda";
    default: return "Неизвестно";
    }
}

const char* get_wifi_standard_name(int code) {
    switch (code) {
    case 1: return "802.11n";
    case 2: return "802.11ac";
    case 3: return "802.11ax";
    default: return "Неизвестно";
    }
}

const char* get_type_name(long float code) {
    int int_code = (int)code; // Приводим long float к int для switch
    switch (int_code) {
    case 1: return "Домашний";
    case 2: return "Офисный";
    case 3: return "Игровой";
    case 4: return "Промышленный";
    default: return "Неизвестно";
    }
}

char get_dual_band_char(int value) {
    return value ? 'y' : 'n';
}

/* ===== ВВОД ===== */
void fill_array(router* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("\n=== Wi-Fi роутер №%d ===\n", i + 1);

        printf("Код производителя (1-D-Link, 2-TP-Link, 3-Asus, 4-ZyXEL, 5-Netgear, 6-Tenda): ");
        while (scanf("%d", &arr[i].manufacturer_code) != 1 || arr[i].manufacturer_code < 1 || arr[i].manufacturer_code > 6) {
            printf("Некорректные данные. Введите число от 1 до 6: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        printf("Скорость по проводному подключению (Мбит/с, 100-10000): ");
        while (scanf("%lf", &arr[i].wired_speed) != 1 || arr[i].wired_speed < 100 || arr[i].wired_speed > 10000) {
            printf("Некорректные данные. Введите число от 100 до 10000: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        printf("Код стандарта Wi-Fi (1-802.11n, 2-802.11ac, 3-802.11ax): ");
        while (scanf("%d", &arr[i].wifi_standard_code) != 1 || arr[i].wifi_standard_code < 1 || arr[i].wifi_standard_code > 3) {
            printf("Некорректные данные. Введите число от 1 до 3: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        printf("Работа в двух диапазонах (1-да, 0-нет): ");
        while (scanf("%d", &arr[i].dual_band) != 1 || (arr[i].dual_band != 0 && arr[i].dual_band != 1)) {
            printf("Некорректные данные. Введите 0 или 1: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        printf("Код типа роутера (1-домашний, 2-офисный, 3-игровой, 4-промышленный): ");
        while (scanf("%Lf", &arr[i].type_code) != 1 || arr[i].type_code < 1 || arr[i].type_code > 4) {
            printf("Некорректные данные. Введите число от 1 до 4: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        printf("Количество LAN портов (можно дробное, 0-8): ");
        while (scanf("%f", &arr[i].lan_ports) != 1 || arr[i].lan_ports < 0 || arr[i].lan_ports > 8) {
            printf("Некорректные данные. Введите число от 0 до 8: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        printf("Подходит для онлайн-игр (1-да, 0-нет): ");
        while (scanf("%d", &arr[i].gaming) != 1 || (arr[i].gaming != 0 && arr[i].gaming != 1)) {
            printf("Некорректные данные. Введите 0 или 1: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        printf("Функции VPN (1-да, 0-нет): ");
        while (scanf("%d", &arr[i].vpn_support) != 1 || (arr[i].vpn_support != 0 && arr[i].vpn_support != 1)) {
            printf("Некорректные данные. Введите 0 или 1: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        printf("Поддержка MESH (1-да, 0-нет): ");
        while (scanf("%d", &arr[i].mesh_support) != 1 || (arr[i].mesh_support != 0 && arr[i].mesh_support != 1)) {
            printf("Некорректные данные. Введите 0 или 1: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        printf("Максимальная скорость Wi-Fi (Мбит/с, 150-10000): ");
        while (scanf("%Lf", &arr[i].max_wifi_speed) != 1 || arr[i].max_wifi_speed < 150 || arr[i].max_wifi_speed > 10000) {
            printf("Некорректные данные. Введите число от 150 до 10000: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        printf("Наличие USB разъема (1-да, 0-нет): ");
        while (scanf("%d", &arr[i].usb_port) != 1 || (arr[i].usb_port != 0 && arr[i].usb_port != 1)) {
            printf("Некорректные данные. Введите 0 или 1: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        printf("Мобильный выход в интернет (1-да, 0-нет): ");
        while (scanf("%d", &arr[i].mobile_internet) != 1 || (arr[i].mobile_internet != 0 && arr[i].mobile_internet != 1)) {
            printf("Некорректные данные. Введите 0 или 1: ");
            clear_input_buffer();
        }
        clear_input_buffer();
    }
}

/* ===== ВЫВОД ===== */
void print_router(router r) {
    printf("| %-12s | %8.2lf | %-12s | %-3c | %-10s | %-5.1f | %-4d | %-4d | %-5s | %10.0Lf | %-4s | %-10s |\n",
        get_manufacturer_name(r.manufacturer_code),
        r.wired_speed, // ИЗМЕНЕНО на %lf
        get_wifi_standard_name(r.wifi_standard_code),
        get_dual_band_char(r.dual_band),
        get_type_name(r.type_code),
        r.lan_ports,
        r.gaming,
        r.vpn_support,
        r.mesh_support ? "Да" : "Нет",
        r.max_wifi_speed,
        r.usb_port ? "Да" : "Нет",
        r.mobile_internet ? "Да" : "Нет");
}

void print_table_header() {
    printf("\n===========================================================================================================================================================================================\n");
    printf("| Производитель |  Провод  | Стандарт Wi-Fi |2дс| Тип        | LAN  | Игры | VPN  | MESH  |   Wi-Fi   | USB  | Мобильный |\n");
    printf("===========================================================================================================================================================================================\n");
}

void print_array(router* arr, int size) {
    print_table_header();
    for (int i = 0; i < size; i++)
        print_router(arr[i]);
    printf("===========================================================================================================================================================================================\n");
}

/* ===== ПОИСК (добавлен поиск по производителю) ===== */
void search_by_fields(router* arr, int size, int manufacturer_target, int vpn_target, long double wifi_speed_target,
    int use_manufacturer, int use_vpn, int use_wifi_speed) {
    int found = 0;
    print_table_header();
    for (int i = 0; i < size; i++) {
        if (use_manufacturer && arr[i].manufacturer_code != manufacturer_target)
            continue;
        if (use_vpn && arr[i].vpn_support != vpn_target)
            continue;
        if (use_wifi_speed && arr[i].max_wifi_speed != wifi_speed_target)
            continue;
        print_router(arr[i]);
        found = 1;
    }
    if (!found) {
        printf("Роутеры не найдены\n");
    }
}

void search_by_manufacturer(router* arr, int size, int target_manufacturer) {
    search_by_fields(arr, size, target_manufacturer, 0, 0, 1, 0, 0);
}

void search_by_vpn(router* arr, int size, int target_vpn) {
    search_by_fields(arr, size, 0, target_vpn, 0, 0, 1, 0);
}

void search_by_wifi_speed(router* arr, int size, long double target_speed) {
    search_by_fields(arr, size, 0, 0, target_speed, 0, 0, 1);
}

/* ===== СОРТИРОВКИ (по всем полям) ===== */
int compare_manufacturer(const void* a, const void* b) {
    return ((router*)a)->manufacturer_code - ((router*)b)->manufacturer_code;
}

int compare_wired_speed(const void* a, const void* b) {
    double diff = ((router*)a)->wired_speed - ((router*)b)->wired_speed;
    if (diff > 0) return 1;
    if (diff < 0) return -1;
    return 0;
}

int compare_wifi_standard(const void* a, const void* b) {
    return ((router*)a)->wifi_standard_code - ((router*)b)->wifi_standard_code;
}

int compare_dual_band(const void* a, const void* b) {
    return ((router*)a)->dual_band - ((router*)b)->dual_band;
}

int compare_type(const void* a, const void* b) {
    long float diff = ((router*)a)->type_code - ((router*)b)->type_code;
    if (diff > 0) return 1;
    if (diff < 0) return -1;
    return 0;
}

int compare_lan_ports(const void* a, const void* b) {
    float diff = ((router*)a)->lan_ports - ((router*)b)->lan_ports;
    if (diff > 0) return 1;
    if (diff < 0) return -1;
    return 0;
}

int compare_gaming(const void* a, const void* b) {
    return ((router*)a)->gaming - ((router*)b)->gaming;
}

int compare_vpn_support(const void* a, const void* b) {
    return ((router*)a)->vpn_support - ((router*)b)->vpn_support;
}

int compare_mesh_support(const void* a, const void* b) {
    return ((router*)a)->mesh_support - ((router*)b)->mesh_support;
}

int compare_max_wifi_speed(const void* a, const void* b) {
    long double diff = ((router*)a)->max_wifi_speed - ((router*)b)->max_wifi_speed;
    if (diff > 0) return 1;
    if (diff < 0) return -1;
    return 0;
}

int compare_usb_port(const void* a, const void* b) {
    return ((router*)a)->usb_port - ((router*)b)->usb_port;
}

int compare_mobile_internet(const void* a, const void* b) {
    return ((router*)a)->mobile_internet - ((router*)b)->mobile_internet;
}

/* ===== ИЗМЕНЕНИЕ ЗАПИСИ ===== */
void modify_record(router* arr, int index, int size) {
    if (index < 0 || index >= size) {
        printf("Такой записи нет!\n");
        return;
    }

    printf("\n=== Изменение роутера №%d ===\n", index + 1);

    printf("Код производителя (1-D-Link, 2-TP-Link, 3-Asus, 4-ZyXEL, 5-Netgear, 6-Tenda): ");
    while (scanf("%d", &arr[index].manufacturer_code) != 1 || arr[index].manufacturer_code < 1 || arr[index].manufacturer_code > 6) {
        printf("Некорректно. Введите число от 1 до 6: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Скорость по проводному подключению (Мбит/с, 100-10000): ");
    while (scanf("%lf", &arr[index].wired_speed) != 1 || arr[index].wired_speed < 100 || arr[index].wired_speed > 10000) {
        printf("Некорректно. Введите число от 100 до 10000: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Код стандарта Wi-Fi (1-802.11n, 2-802.11ac, 3-802.11ax): ");
    while (scanf("%d", &arr[index].wifi_standard_code) != 1 || arr[index].wifi_standard_code < 1 || arr[index].wifi_standard_code > 3) {
        printf("Некорректно. Введите число от 1 до 3: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Работа в двух диапазонах (1-да, 0-нет): ");
    while (scanf("%d", &arr[index].dual_band) != 1 || (arr[index].dual_band != 0 && arr[index].dual_band != 1)) {
        printf("Некорректно. Введите 0 или 1: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Код типа роутера (1-домашний, 2-офисный, 3-игровой, 4-промышленный): ");
    while (scanf("%Lf", &arr[index].type_code) != 1 || arr[index].type_code < 1 || arr[index].type_code > 4) {
        printf("Некорректно. Введите число от 1 до 4: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Количество LAN портов (можно дробное, 0-8): ");
    while (scanf("%f", &arr[index].lan_ports) != 1 || arr[index].lan_ports < 0 || arr[index].lan_ports > 8) {
        printf("Некорректно. Введите число от 0 до 8: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Подходит для онлайн-игр (1-да, 0-нет): ");
    while (scanf("%d", &arr[index].gaming) != 1 || (arr[index].gaming != 0 && arr[index].gaming != 1)) {
        printf("Некорректно. Введите 0 или 1: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Функции VPN (1-да, 0-нет): ");
    while (scanf("%d", &arr[index].vpn_support) != 1 || (arr[index].vpn_support != 0 && arr[index].vpn_support != 1)) {
        printf("Некорректно. Введите 0 или 1: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Поддержка MESH (1-да, 0-нет): ");
    while (scanf("%d", &arr[index].mesh_support) != 1 || (arr[index].mesh_support != 0 && arr[index].mesh_support != 1)) {
        printf("Некорректно. Введите 0 или 1: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Максимальная скорость Wi-Fi (Мбит/с, 150-10000): ");
    while (scanf("%Lf", &arr[index].max_wifi_speed) != 1 || arr[index].max_wifi_speed < 150 || arr[index].max_wifi_speed > 10000) {
        printf("Некорректно. Введите число от 150 до 10000: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Наличие USB разъема (1-да, 0-нет): ");
    while (scanf("%d", &arr[index].usb_port) != 1 || (arr[index].usb_port != 0 && arr[index].usb_port != 1)) {
        printf("Некорректно. Введите 0 или 1: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Мобильный выход в интернет (1-да, 0-нет): ");
    while (scanf("%d", &arr[index].mobile_internet) != 1 || (arr[index].mobile_internet != 0 && arr[index].mobile_internet != 1)) {
        printf("Некорректно. Введите 0 или 1: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Запись успешно изменена!\n");
}

/* ===== ФАЙЛОВЫЕ ОПЕРАЦИИ ===== */
void save_to_file(const char* name, router* arr, int size) {
    FILE* f = fopen(name, "w");
    if (!f) {
        printf("Не удалось открыть файл для записи!\n");
        return;
    }

    fprintf(f, "| Производитель |  Провод  | Стандарт Wi-Fi |2дс| Тип        | LAN  | Игры | VPN  | MESH  |   Wi-Fi   | USB  | Мобильный |\n");
    fprintf(f, "===========================================================================================================================================================================================\n");

    for (int i = 0; i < size; i++) {
        fprintf(f, "| %-12s | %8.2lf | %-12s | %-3c | %-10s | %-5.1f | %-4d | %-4d | %-5s | %10.0Lf | %-4s | %-10s |\n",
            get_manufacturer_name(arr[i].manufacturer_code),
            arr[i].wired_speed,
            get_wifi_standard_name(arr[i].wifi_standard_code),
            get_dual_band_char(arr[i].dual_band),
            get_type_name(arr[i].type_code),
            arr[i].lan_ports,
            arr[i].gaming,
            arr[i].vpn_support,
            arr[i].mesh_support ? "Да" : "Нет",
            arr[i].max_wifi_speed,
            arr[i].usb_port ? "Да" : "Нет",
            arr[i].mobile_internet ? "Да" : "Нет");
    }

    fclose(f);
    printf("Данные успешно сохранены в файл '%s'\n", name);
}

void load_from_file(const char* name, router* arr, int size) {
    FILE* f = fopen(name, "r");
    if (!f) {
        printf("Не удалось открыть файл '%s'\n", name);
        return;
    }

    char buffer[512];
    fgets(buffer, sizeof(buffer), f);
    fgets(buffer, sizeof(buffer), f);

    for (int i = 0; i < size; i++) {
        if (fgets(buffer, sizeof(buffer), f) == NULL) break;

        char manufacturer[20], wifi_std[15], type[15];
        char dual_band_char;
        char mesh_str[4], usb_str[4], mobile_str[10];

        sscanf(buffer, "| %s | %lf | %s | %c | %s | %f | %d | %d | %s | %Lf | %s | %s |",
            manufacturer, &arr[i].wired_speed, wifi_std, &dual_band_char,
            type, &arr[i].lan_ports, &arr[i].gaming, &arr[i].vpn_support,
            mesh_str, &arr[i].max_wifi_speed, usb_str, mobile_str);

        // Преобразуем названия обратно в коды
        if (strcmp(manufacturer, "D-Link") == 0) arr[i].manufacturer_code = 1;
        else if (strcmp(manufacturer, "TP-Link") == 0) arr[i].manufacturer_code = 2;
        else if (strcmp(manufacturer, "Asus") == 0) arr[i].manufacturer_code = 3;
        else if (strcmp(manufacturer, "ZyXEL") == 0) arr[i].manufacturer_code = 4;
        else if (strcmp(manufacturer, "Netgear") == 0) arr[i].manufacturer_code = 5;
        else if (strcmp(manufacturer, "Tenda") == 0) arr[i].manufacturer_code = 6;
        else arr[i].manufacturer_code = 0;

        if (strcmp(wifi_std, "802.11n") == 0) arr[i].wifi_standard_code = 1;
        else if (strcmp(wifi_std, "802.11ac") == 0) arr[i].wifi_standard_code = 2;
        else if (strcmp(wifi_std, "802.11ax") == 0) arr[i].wifi_standard_code = 3;
        else arr[i].wifi_standard_code = 0;

        arr[i].dual_band = (dual_band_char == 'y') ? 1 : 0;

        // Для типа нужно преобразовать строку обратно в long float
        if (strcmp(type, "Домашний") == 0) arr[i].type_code = 1.0L;
        else if (strcmp(type, "Офисный") == 0) arr[i].type_code = 2.0L;
        else if (strcmp(type, "Игровой") == 0) arr[i].type_code = 3.0L;
        else if (strcmp(type, "Промышленный") == 0) arr[i].type_code = 4.0L;
        else arr[i].type_code = 0.0L;

        arr[i].mesh_support = (strcmp(mesh_str, "Да") == 0) ? 1 : 0;
        arr[i].usb_port = (strcmp(usb_str, "Да") == 0) ? 1 : 0;
        arr[i].mobile_internet = (strcmp(mobile_str, "Да") == 0) ? 1 : 0;
    }

    fclose(f);
    printf("Данные успешно загружены из файла '%s'\n", name);
}

/* ===== ДОБАВЛЕНИЕ ЗАПИСЕЙ В МАССИВ ===== */
router* add_records_to_array(router* arr, int* current_size, int new_records_count) {
    int new_size = *current_size + new_records_count;
    router* new_arr = (router*)realloc(arr, new_size * sizeof(router));

    if (!new_arr) {
        printf("Ошибка выделения памяти!\n");
        return arr;
    }

    printf("\n=== Ввод %d новых роутеров ===\n", new_records_count);
    for (int i = *current_size; i < new_size; i++) {
        printf("\n=== Wi-Fi роутер №%d ===\n", i + 1);

        printf("Код производителя (1-D-Link, 2-TP-Link, 3-Asus, 4-ZyXEL, 5-Netgear, 6-Tenda): ");
        scanf("%d", &new_arr[i].manufacturer_code);
        clear_input_buffer();

        printf("Скорость по проводному подключению (Мбит/с): ");
        scanf("%lf", &new_arr[i].wired_speed);
        clear_input_buffer();

        printf("Код стандарта Wi-Fi (1-802.11n, 2-802.11ac, 3-802.11ax): ");
        scanf("%d", &new_arr[i].wifi_standard_code);
        clear_input_buffer();

        printf("Работа в двух диапазонах (1-да, 0-нет): ");
        scanf("%d", &new_arr[i].dual_band);
        clear_input_buffer();

        printf("Код типа роутера (1-домашний, 2-офисный, 3-игровой, 4-промышленный): ");
        scanf("%Lf", &new_arr[i].type_code);
        clear_input_buffer();

        printf("Количество LAN портов: ");
        scanf("%f", &new_arr[i].lan_ports);
        clear_input_buffer();

        printf("Подходит для онлайн-игр (1-да, 0-нет): ");
        scanf("%d", &new_arr[i].gaming);
        clear_input_buffer();

        printf("Функции VPN (1-да, 0-нет): ");
        scanf("%d", &new_arr[i].vpn_support);
        clear_input_buffer();

        printf("Поддержка MESH (1-да, 0-нет): ");
        scanf("%d", &new_arr[i].mesh_support);
        clear_input_buffer();

        printf("Максимальная скорость Wi-Fi (Мбит/с): ");
        scanf("%Lf", &new_arr[i].max_wifi_speed);
        clear_input_buffer();

        printf("Наличие USB разъема (1-да, 0-нет): ");
        scanf("%d", &new_arr[i].usb_port);
        clear_input_buffer();

        printf("Мобильный выход в интернет (1-да, 0-нет): ");
        scanf("%d", &new_arr[i].mobile_internet);
        clear_input_buffer();
    }

    *current_size = new_size;
    printf("Добавлено %d новых записей. Всего записей: %d\n", new_records_count, new_size);
    return new_arr;
}

/* ===== MAIN ===== */
int main() {
    setlocale(LC_ALL, "RUS");

    int size = 0;
    router* arr = NULL;
    int choice;
    char filename[50];

    printf("=== База данных Wi-Fi роутеров ===\n\n");

    do {
        printf("\n=== ГЛАВНОЕ МЕНЮ ===\n");
        printf("1 - Создание новой базы данных\n");
        printf("2 - Поиск роутера по параметрам\n");
        printf("3 - Сортировка базы данных\n");
        printf("4 - Изменение записи\n");
        printf("5 - Сохранение базы в файл\n");
        printf("6 - Загрузка базы из файла\n");
        printf("7 - Добавление новых записей\n");
        printf("0 - Выход\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
        case 1: {
            printf("Введите количество роутеров в базе: ");
            scanf("%d", &size);
            clear_input_buffer();

            while (size <= 0) {
                printf("Некорректный размер! Введите снова: ");
                scanf("%d", &size);
                clear_input_buffer();
            }

            if (arr) free(arr);
            arr = (router*)malloc(size * sizeof(router));
            if (!arr) {
                printf("Ошибка выделения памяти!\n");
                return 1;
            }

            fill_array(arr, size);
            print_array(arr, size);
            break;
        }

        case 2: {
            if (!arr || size == 0) {
                printf("База данных пуста! Сначала создайте базу.\n");
                break;
            }

            int search_choice;
            printf("\n=== ПОИСК РОУТЕРА ===\n");
            printf("1 - По производителю\n");
            printf("2 - По поддержке VPN\n");
            printf("3 - По скорости Wi-Fi\n");
            printf("4 - По Производителю\n");
            printf("Выберите параметр поиска: ");
            scanf("%d", &search_choice);
            clear_input_buffer();

            if (search_choice == 1) {
                int target_manufacturer;
                printf("\nВыберите производителя:\n");
                printf("1 - D-Link\n");
                printf("2 - TP-Link\n");
                printf("3 - Asus\n");
                printf("4 - ZyXEL\n");
                printf("5 - Netgear\n");
                printf("6 - Tenda\n");
                printf("Введите код производителя: ");
                scanf("%d", &target_manufacturer);
                clear_input_buffer();
                search_by_manufacturer(arr, size, target_manufacturer);
            }
            else if (search_choice == 2) {
                int target_vpn;
                printf("Поддержка VPN (1-да, 0-нет): ");
                scanf("%d", &target_vpn);
                clear_input_buffer();
                search_by_vpn(arr, size, target_vpn);
            }
            else if (search_choice == 3) {
                long double target_speed;
                printf("Скорость Wi-Fi (Мбит/с): ");
                scanf("%Lf", &target_speed);
                clear_input_buffer();
                search_by_wifi_speed(arr, size, target_speed);
            }
            else if (search_choice == 4) {
                int target_manufacturer, target_vpn;
                printf("\nВыберите производителя:\n");
                printf("1 - D-Link\n");
                printf("2 - TP-Link\n");
                printf("3 - Asus\n");
                printf("4 - ZyXEL\n");
                printf("5 - Netgear\n");
                printf("6 - Tenda\n");
                printf("Введите код производителя: ");
                scanf("%d", &target_manufacturer);
                clear_input_buffer();
                printf("Поддержка VPN (1-да, 0-нет): ");
                scanf("%d", &target_vpn);
                clear_input_buffer();
                search_by_fields(arr, size, target_manufacturer, target_vpn, 0, 1, 1, 0);
            }
            else if (search_choice == 5) {
                int target_manufacturer;
                long double target_speed;
                printf("\nВыберите производителя:\n");
                printf("1 - D-Link\n");
                printf("2 - TP-Link\n");
                printf("3 - Asus\n");
                printf("4 - ZyXEL\n");
                printf("5 - Netgear\n");
                printf("6 - Tenda\n");
                printf("Введите код производителя: ");
                scanf("%d", &target_manufacturer);
                clear_input_buffer();
                printf("Скорость Wi-Fi (Мбит/с): ");
                scanf("%Lf", &target_speed);
                clear_input_buffer();
                search_by_fields(arr, size, target_manufacturer, 0, target_speed, 1, 0, 1);
            }
            else if (search_choice == 6) {
                int target_vpn;
                long double target_speed;
                printf("Поддержка VPN (1-да, 0-нет): ");
                scanf("%d", &target_vpn);
                clear_input_buffer();
                printf("Скорость Wi-Fi (Мбит/с): ");
                scanf("%Lf", &target_speed);
                clear_input_buffer();
                search_by_fields(arr, size, 0, target_vpn, target_speed, 0, 1, 1);
            }
            else if (search_choice == 7) {
                int target_manufacturer, target_vpn;
                long double target_speed;
                printf("\nВыберите производителя:\n");
                printf("1 - D-Link\n");
                printf("2 - TP-Link\n");
                printf("3 - Asus\n");
                printf("4 - ZyXEL\n");
                printf("5 - Netgear\n");
                printf("6 - Tenda\n");
                printf("Введите код производителя: ");
                scanf("%d", &target_manufacturer);
                clear_input_buffer();
                printf("Поддержка VPN (1-да, 0-нет): ");
                scanf("%d", &target_vpn);
                clear_input_buffer();
                printf("Скорость Wi-Fi (Мбит/с): ");
                scanf("%Lf", &target_speed);
                clear_input_buffer();
                search_by_fields(arr, size, target_manufacturer, target_vpn, target_speed, 1, 1, 1);
            }
            else {
                printf("Неверный пункт меню!\n");
            }
            break;
        }

        case 3: {
            if (!arr || size == 0) {
                printf("База данных пуста! Сначала создайте базу.\n");
                break;
            }

            int sort_choice;
            printf("\n=== СОРТИРОВКА БАЗЫ ДАННЫХ ===\n");
            printf("1 - По производителю\n");
            printf("2 - По скорости проводного подключения\n");
            printf("3 - По стандарту Wi-Fi\n");
            printf("4 - По работе в двух диапазонах\n");
            printf("5 - По типу роутера\n");
            printf("6 - По количеству LAN портов\n");
            printf("7 - По поддержке игр\n");
            printf("8 - По поддержке VPN\n");
            printf("9 - По поддержке MESH\n");
            printf("10 - По скорости Wi-Fi\n");
            printf("11 - По наличию USB\n");
            printf("12 - По мобильному интернету\n");
            printf("Выберите поле для сортировки: ");
            scanf("%d", &sort_choice);
            clear_input_buffer();

            switch (sort_choice) {
            case 1: qsort(arr, size, sizeof(router), compare_manufacturer); break;
            case 2: qsort(arr, size, sizeof(router), compare_wired_speed); break;
            case 3: qsort(arr, size, sizeof(router), compare_wifi_standard); break;
            case 4: qsort(arr, size, sizeof(router), compare_dual_band); break;
            case 5: qsort(arr, size, sizeof(router), compare_type); break;
            case 6: qsort(arr, size, sizeof(router), compare_lan_ports); break;
            case 7: qsort(arr, size, sizeof(router), compare_gaming); break;
            case 8: qsort(arr, size, sizeof(router), compare_vpn_support); break;
            case 9: qsort(arr, size, sizeof(router), compare_mesh_support); break;
            case 10: qsort(arr, size, sizeof(router), compare_max_wifi_speed); break;
            case 11: qsort(arr, size, sizeof(router), compare_usb_port); break;
            case 12: qsort(arr, size, sizeof(router), compare_mobile_internet); break;
            default: printf("Неверный пункт меню!\n"); break;
            }

            if (sort_choice >= 1 && sort_choice <= 12) {
                printf("\nБаза данных отсортирована!\n");
                print_array(arr, size);
            }
            break;
        }

        case 4: {
            if (!arr || size == 0) {
                printf("База данных пуста! Сначала создайте базу.\n");
                break;
            }

            int index;
            printf("Введите номер записи для изменения (1-%d): ", size);
            scanf("%d", &index);
            clear_input_buffer();
            index--; // Переводим в 0-based индекс

            if (index >= 0 && index < size) {
                modify_record(arr, index, size);
                printf("\nОбновленная база данных:\n");
                print_array(arr, size);
            }
            else {
                printf("Неверный номер записи!\n");
            }
            break;
        }

        case 5: {
            if (!arr || size == 0) {
                printf("База данных пуста! Сначала создайте базу.\n");
                break;
            }

            printf("Введите имя файла для сохранения: ");
            scanf("%49s", filename);
            clear_input_buffer();
            save_to_file(filename, arr, size);
            break;
        }

        case 6: {
            printf("Введите имя файла для загрузки: ");
            scanf("%49s", filename);
            clear_input_buffer();

            printf("Введите количество записей для загрузки: ");
            scanf("%d", &size);
            clear_input_buffer();

            if (size <= 0) {
                printf("Некорректный размер!\n");
                break;
            }

            if (arr) free(arr);
            arr = (router*)malloc(size * sizeof(router));
            if (!arr) {
                printf("Ошибка выделения памяти!\n");
                return 1;
            }

            load_from_file(filename, arr, size);
            printf("\nЗагруженная база данных:\n");
            print_array(arr, size);
            break;
        }

        case 7: {
            if (!arr) {
                printf("База данных не инициализирована! Сначала создайте базу.\n");
                break;
            }

            int new_records;
            printf("Сколько записей добавить? ");
            scanf("%d", &new_records);
            clear_input_buffer();

            if (new_records <= 0) {
                printf("Некорректное количество!\n");
                break;
            }

            arr = add_records_to_array(arr, &size, new_records);
            printf("\nОбновленная база данных (%d записей):\n", size);
            print_array(arr, size);
            break;
        }

        case 0:
            printf("Выход из программы...\n");
            break;

        default:
            printf("Неверный пункт меню! Попробуйте снова.\n");
            break;
        }
    } while (choice != 0);

    if (arr) free(arr);
    return 0;
}