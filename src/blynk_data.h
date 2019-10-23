void start(int checkStart);

BLYNK_WRITE(V0) // Пресеты
{
    if (param.asInt() == 1)
    { // Курица
        time_sushki = 24;
        rejim = 2;
        temp_sushki = 10;
    }
    else if (param.asInt() == 2)
    { // Курица +
        time_sushki = 24;
        rejim = 3;
        temp_sushki = 25;
    }
    else if (param.asInt() == 3)
    { // Говядина
        time_sushki = 48;
        rejim = 2;
        temp_sushki = 10;
    }
    else if (param.asInt() == 4)
    { // Говядина +
        time_sushki = 48;
        rejim = 3;
        temp_sushki = 30;
    }
    Blynk.virtualWrite(1, time_sushki);
    Blynk.virtualWrite(2, rejim);
    Blynk.virtualWrite(3, temp_sushki);
}

BLYNK_WRITE(V1) // Время сушки
{
    time_sushki = param.asInt();
}

BLYNK_WRITE(V2) // Режим сушки
{
    rejim = param.asInt();
}

BLYNK_WRITE(V3) // Температура сушки
{
    temp_sushki = param.asInt();
}

BLYNK_WRITE(V5) // реле
{
    start(param.asInt());
}

