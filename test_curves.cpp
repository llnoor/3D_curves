printf("\nfirst_container:\n");

    for(int i=0; i < (int) first_container.size(); i++) {
        printf("\nNumber_of_curve: %d Type: %d\n", i, first_container[i]->getType());
        printf("Point           :\t");
        first_container[i]->getPoints(M_PI/4).display();
        printf("DerivativePoints:\t");
        first_container[i]->getDerivativePoints(M_PI/4).display();
    }


    printf("\nchange data\nsecond_container:\n");


    for(int i=0; i < (int) second_container.size(); i++) {
        second_container[i]->change_data();
        printf("\nNumber_of_curve: %d Type: %d\n", i, second_container[i]->getType());
        printf("Point           :\t");
        second_container[i]->getPoints(M_PI/4).display();
        printf("DerivativePoints:\t");
        second_container[i]->getDerivativePoints(M_PI/4).display();
    }

    printf("\nfirst_container:\n");

    for(int i=0; i < (int) first_container.size(); i++) {
        printf("\nNumber_of_curve: %d Type: %d\n", i, first_container[i]->getType());
        printf("Point           :\t");
        first_container[i]->getPoints(M_PI/4).display();
        printf("DerivativePoints:\t");
        first_container[i]->getDerivativePoints(M_PI/4).display();
    }