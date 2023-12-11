CREATE DATABASE IF NOT EXISTS backend_template;
USE backend_template;
CREATE TABLE IF NOT EXISTS examples (
   id INT AUTO_INCREMENT,
   name VARCHAR(255),
   PRIMARY KEY(id)
);