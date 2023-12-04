#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

struct tree_element {
    char name[20];
    int x, y, ftype, lx, rx, nc, level;
    struct tree_element *link[5];
};

typedef struct tree_element node;

void create(node **root, int lev, char *dname, int lx, int rx, int x) {
    int i, gap;
    if (*root == NULL) {
        (*root) = (node *)malloc(sizeof(node));
        printf("Enter name of dir/file(under %s) :", dname);
        fflush(stdin);
        gets((*root)->name);
        printf("enter 1 for Dir/2 for file :");
        scanf("%d", &(*root)->ftype);
        (*root)->level = lev;
        (*root)->y = 50 + lev * 50;
        (*root)->x = x;
        (*root)->lx = lx;
        (*root)->rx = rx;
        for (i = 0; i < 5; i++)
            (*root)->link[i] = NULL;
        if ((*root)->ftype == 1) {
            printf("No of sub directories/files(for %s):", (*root)->name);
            scanf("%d", &(*root)->nc);
            if ((*root)->nc == 0)
                gap = rx - lx;
            else
                gap = (rx - lx) / (*root)->nc;
            for (i = 0; i < (*root)->nc; i++)
                create(&((*root)->link[i]), lev + 1, (*root)->name, lx + gap * i, lx + gap * i + gap, lx + gap * i + gap / 2);
        } else
            (*root)->nc = 0;
    }
}

void display(node *root, SDL_Renderer *renderer) {
    int i;
    if (root != NULL) {
        for (i = 0; i < root->nc; i++) {
            SDL_RenderDrawLine(renderer, root->x, root->y, root->link[i]->x, root->link[i]->y);
        }
        if (root->ftype == 1)
            SDL_RenderDrawRect(renderer, &(SDL_Rect){root->x - 20, root->y - 10, 40, 20});
        else
            SDL_RenderDrawPoint(renderer, root->x, root->y);
        SDL_RenderPresent(renderer);
        for (i = 0; i < root->nc; i++) {
            display(root->link[i], renderer);
        }
    }
}

int main() {
    node *root = NULL;
    create(&root, 0, "root", 0, 639, 320);

    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    display(root, renderer);
    SDL_Delay(5000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
