#include <stdio.h>

int main ()
{
    float monto_total, cantidad, precio, monto_final, descuento = 0;

    printf("Ingrese la cantidad de productos a comprarse: ");
    scanf("%f", &cantidad);
    printf("Ingrese el precio de cada producto a comprarse: ");
    scanf("%f", &precio);

    monto_total = cantidad * precio;
    descuento = monto_total * 0.15;

    if (monto_total > 1000)
    {
        monto_final = monto_total - descuento;
    }

    printf("El precio total es: %2.f\n", monto_total);
    printf("El precio con descuento es igual a: %2.f", monto_final);

    return 0;
}