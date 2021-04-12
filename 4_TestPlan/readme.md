# TEST PLAN:

## Table no: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       |Check if Linked List is created or not                        | (1). NULL Pointer (2). Unique id (3). First name (4). Last name (5). Height (6). Weight (7). Age  (8). Insurance Status (9). vaccine code| Pointer to head node | --TBD-- | Technical|
|  H_01_01       |Check LL initialized from a file                           | (1). Head Pointer (2). File Pointer| LL should be initilized from a file|--TBD--|Scenario/Technical |
|  H_02   |Check Insertion of new data in list| (1). Head Pointer (2). Unique id (3). First name (4). Last name (5). Height (6). Weight (7). Age  (8). Insurance Status (9). vaccine code| SUCCESS |-TBD-|Technical |
| H_02_01 | Check if during insertion id gets stored in file | (1). File name (2). file mode (3). File Pointer | SUCCESS | --TBD | Technical |
| H_02_02 | Check if during insertion no head exists | (1). File name (2). file mode (3). File Pointer | NO_HEAD_EXISTS | --TBD | Technical |
| H_03 | Check if records are displayed properly | (1). Head Pointer | SUCCESS | --TBD | Technical |
| H_03_01 | Check if records in file are displayed properly | (1). File Pointer | SUCCESS | --TBD | Technical |
| H_04 | Check if search by Patient id is working correct | (1). Head pointer (2). Id (3). Result Pointer (4). Flag | SUCCESS | --TBD | Technical |
| H_05 | Check if record is updated properly | (1). Head pointer (2). Id (3). Field to be updated (4). Flag | SUCCESS | --TBD | Technical |
| H_05_01 | Check if record is also updated in File | (1). File Pointer (2). Id | SUCCESS | --TBD | Technical |
| H_06 | Deleting Record | (1). Head pointer (2). Id | Pointer to Head node| --TBD | Technical |
| H_06_01 | If record is only present in List, then delete from List | (1). Head pointer (2). Id | Pointer to head node | --TBD | Technical |
| H_06_02 | If record is only present in File, then delete from File | (1). File pointers (2). Id | SUCCESS | --TBD | Technical |
| H_06_03 | If record is deleted, then Index from Index File should also be deleted | (1). File pointers (2). Id | SUCCESS | --TBD | Technical |
| H_07 | When program shuts down records should be saved in File | (1). File pointers (2). Head Pointer| SUCCESS | --TBD | Technical |
| H_07_01 | When program Shuts down all allocated Memory Locations should be freed | (1). Head Pointer| No Memory Leaks | --TBD | Technical |



## Table no: Low level test plan

| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |--------------------------------------------------------------|  ------------|-------------|----------------|Requirement based |
|  L_02       |--------------------------------------------------------------|  ------------|-------------|----------------|Scenario based    |
|  L_03       |--------------------------------------------------------------|  ------------|-------------|----------------|Boundary based    |
