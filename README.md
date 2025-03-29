# Supplier and Product Management System 🏭📦  

C++ application for managing suppliers and products (technology, tools, equipment), with file persistence and inventory operations.  

---

### 🌟 Key Features  
- **Supplier Management**:  
  - Register suppliers with ID, name, category, and nationality.  
  - Link products to specific suppliers.  

- **Product Types**:  
  - **Technology**: Attributes like AI support (e.g., servers, routers).  
  - **Tools**: Safety level and category (e.g., drills, saws).  
  - **Equipment**: Material and weight (e.g., cranes, hydraulic presses).  

- **Data Persistence**:  
  - Save/load suppliers and products to/from text files (`Proveedores.txt`, `Productos.txt`).  

- **CRUD Operations**:  
  - Add, delete, or update products/suppliers.  
  - Filter products by type or supplier.  

- **Custom Linked Lists**:  
  - Dynamic inventory management using templated lists (`Lista.h`).  

---

### 📂 Project Structure  
| File                  | Description                                  |  
|-----------------------|----------------------------------------------|  
| `Proveedor.cpp/h`     | Supplier class (ID, name, category, national). |  
| `Producto.cpp/h`      | Abstract product class (name, price, linked supplier). |  
| `Tecnologia.cpp/h`    | Technology products with AI support flag.     |  
| `Herramienta.cpp/h`   | Tools with safety level and category.         |  
| `Equipamiento.cpp/h`  | Industrial equipment with material and weight.|  
| `Lista.h`             | Templated linked list for data storage.       |  
| `Archivos.cpp/h`      | Handles file I/O for suppliers and products.  |  

---

### 🛠️ SOLID Principles Implementation  
1. **Single Responsibility**:  
   - `Proveedor` handles supplier data only.  
   - `Archivos` manages file operations separately.  

2. **Open/Closed**:  
   - New product types (e.g., `Food`) can be added by extending `Producto`.  

3. **Liskov Substitution**:  
   - Subclasses (`Tecnologia`, `Herramienta`) inherit from `Producto` without altering core behavior.  

4. **Interface Segregation**:  
   - Product-specific methods (e.g., `getIA()` for `Tecnologia`) avoid bloating the base class.  

5. **Dependency Inversion**:  
   - `Lista` (template) relies on abstractions for serialization, not concrete implementations.  

---

### 📧 Contact  
**Author**: Bryan Agüero Mata 
**Email**: [Bryancr1208@gmail.com](mailto:Bryancr1208@gmail.com )  
