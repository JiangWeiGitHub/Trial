# File Permissions

### Folder & File Permissions

  Page 296 of Book `The Linux Programming Interface`
  ```
  Write: Files may be created in and removed from the directory. Note that it is
  not necessary to have any permission on a file itself in order to be able to
  delete it.
  ```
  
### Test
 + Prerequisite: 
   - User: dragon
   - Path: /home/dragon
   
 + Procedure
   - Test 1
    ```
    mkdir aaa
    cd aaa
    sudo touch bbb.txt
    ls -la
    rm -rf bbb.txt
    ```
    
   - Test 2
    ```
    mkdir aaa
    cd aaa
    echo "bbb.txt" > bbb.txt
    sudo chown root:root bbb.txt
    sudo chmod 000 bbb.txt
    echo "ccc.txt" > ccc.txt
    mv -f ccc.txt bbb.txt
    ls -la
    cat bbb.txt
    ```
