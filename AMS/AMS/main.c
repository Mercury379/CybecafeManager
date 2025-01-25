#include<stdio.h>
#include"menu.h"
#include"card_service.h"
#include"billing_service.h"
#include"rate_service.h"
#include"money_service.h"
#include"rate_service.h"
#include"tool.h"
#include"service.h"
int main() {
	InitCardList();
	InitBillingList();
	InitRateList();
	InitMoneyList();
	InitQueue();
	while (1) {
		if (MainMenu() == 0) {
			break;
		}
	}
	beforeCardExit();
	beforeBillingExit();
	beforeRateExit();
	beforeMoneyExit();
	return 0;
}