
/**
 * @file prototypes.h
 * @author Arnob Chowdhury (https://github.com/arc-arnob)
 * @brief This program is for simulating data manipulation using Linked List
 * @version 0.1
 * @date 2021-04-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __PROTOTYPES_H__
#define __PROTOTYPES_H__

#include<stdio.h>
//#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>


/**
 * @brief Error values for unit testing
 * 
 */
typedef enum error_t{
    ERROR_NULL_PTR = -2,
    SUCCESS = 0,
    START_EXISTS=1,
    NO_HEAD_EXIST=2,
    DATE_INCORRECT=3,
    INVALID_NAME=4,
    ID_EXISTS=5
}error_t;

/**
 * @brief Maps Colors to ints
 * 
 */
typedef enum vaccine{ //color_b -> vaccine
    RED = 0,
    GREEN,
    YELLOW
}vaccine;

typedef enum insured{
    YES = 1,
    NO = 0
}insured;

/**
 * @brief Structure containing details about patient
 * 
 */
typedef struct patient{
    int uniq_id;
    char firstname[100];
    char lastname[100];
    char aadhar_num[20];
    float height;
    float weight;
    int age;
    char date_of_vaccine[12];
    insured insurance;
    vaccine shot;
    struct patient *next;
}patient;



/**
 * @brief Stores number of boxes with given color
 * 
 */
typedef struct vaccine_data{
    int num; // Number of boxes with given color
    vaccine shot; // given color
}vaccine_data;




/**
 * @brief Create a linked list object
 * @param[in] box *  Pointer to head node
 * @param[in] int  id of box
 * @param[in] float  length of box
 * @param[in] float  height of box
 * @param[in] float  weight of box
 * @param[in] float  breadth of box
 * @param[in] color_b color of box
 * @return box* 
 */
patient *create_ll(patient *,int, char *, char *, char *, float, float,int,char *, insured, vaccine);

/**
 * @brief display status of the boxes
 * @param[in]  box * Pointer to start node
 * @return error_t 
 */
error_t display_ll(patient *);

/**
 * @brief Add a new box at the end
 * @param[in] box *  Pointer to head node
 * @param[in] int  id of box
 * @param[in] float  length of box
 * @param[in] float  height of box
 * @param[in] float  weight of box
 * @param[in] float  breadth of box
 * @param[in] color_b color of box
 */
error_t insert_end(patient *,int, char *, char *, char *, float, float,int,char *, insured, vaccine);
/**
 * @brief finds a box by Id
 * @param[in]  box * Pointer to start node
 * @param[out]  box * Pointer to result node
 * @param[in]  int id to be found
 * @return error_t 
 */
error_t find_by_id(patient *, int, patient *, int *);

/**
 * @brief counts all boxes of specific color
 * @param[in]  box * Pointer to start node
 * @param[out]  color_data * Pointer to result enum
 * @param[in] color_b color
 * @return error_t 
 */
error_t count_by_vaccine(patient *, vaccine_data *, vaccine); //Count by insurance
//count_by_color -> count_by_vaccine

/**
 * @brief Updates weight of a box by id
 * @param[in]  box * Pointer to start node
 * @param[in]  int   id to be found
 * @param[in]  box   weight to be updated
 * @return error_t 
 */

/**
 * @brief Updates First Name of the patient
 * 
 * @return error_t 
 */
error_t update_record(patient *, int, int, int); // last int is 0 -> prod , 1 -> testing

/**
 * @brief deletes a patient record by id
 * @param[in]  box * Pointer to start node
 * @param[in]  int   id to be deleted
 * @return error_t 
 */
error_t delete_patient(patient *, int);

/**
 * @brief Deletes all the nodes
 * @param[in]  box * Pointer to start node
 * 
 */
void delete_all(patient *);

/**
 * @brief Deletes one node from the beginning
 * @param[in]  box * Pointer to start node
 * @return box* 
 */
patient *delete_beg(patient *);

/**
 * @brief This validates that patient id is unique
 * 
 * @param fptr 
 * @return error_t 
 */
error_t validate_id(FILE **fptr, int);

/**
 * @brief this file opens and read ids stored.
 * 
 * @param addr 
 * @param mode 
 * @param fptr 
 * @return error_t 
 */
error_t indexFile(char *addr, char *mode ,FILE **fptr);

#endif


