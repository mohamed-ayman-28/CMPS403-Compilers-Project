import os
import subprocess
import tkinter as tk
from tkinter import ttk, scrolledtext, messagebox
from tkinter.filedialog import askopenfilename, asksaveasfilename
import sys

class CompilerApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Compiler Interface")
        self.root.geometry("900x700")
        self.root.minsize(800, 600)
        
        # Store executable path
        self.executable_path = None
        
        # Configure grid layout
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=0)  # Header
        self.root.rowconfigure(1, weight=1)  # Input area
        self.root.rowconfigure(2, weight=0)  # Button area
        self.root.rowconfigure(3, weight=1)  # Output area
        
        # Setup UI components
        self.create_widgets()
        
    def create_widgets(self):
        # Header label
        header_frame = ttk.Frame(self.root)
        header_frame.grid(row=0, column=0, padx=10, pady=(10, 0), sticky="ew")
        
        header_label = ttk.Label(header_frame, text="Compiler Interface", font=("Arial", 16, "bold"))
        header_label.pack(side=tk.LEFT)
        
        # Input area
        input_frame = ttk.LabelFrame(self.root, text="Code Input")
        input_frame.grid(row=1, column=0, padx=10, pady=10, sticky="nsew")
        input_frame.columnconfigure(0, weight=1)
        input_frame.rowconfigure(0, weight=1)
        
        self.code_input = scrolledtext.ScrolledText(input_frame, wrap=tk.WORD, font=('Courier', 10))
        self.code_input.grid(row=0, column=0, padx=5, pady=5, sticky="nsew")
        
        # Button area
        button_frame = ttk.Frame(self.root)
        button_frame.grid(row=2, column=0, padx=10, pady=(0, 10), sticky="ew")
        
        self.compile_button = ttk.Button(button_frame, text="Compile", command=self.compile_code)
        self.compile_button.pack(side=tk.LEFT, padx=5)
        
        self.open_button = ttk.Button(button_frame, text="Open File", command=self.open_file)
        self.open_button.pack(side=tk.LEFT, padx=5)
        
        self.save_button = ttk.Button(button_frame, text="Save Input", command=self.save_file)
        self.save_button.pack(side=tk.LEFT, padx=5)
        
        self.select_exe_button = ttk.Button(button_frame, text="Select Compiler", command=self.select_executable)
        self.select_exe_button.pack(side=tk.LEFT, padx=5)
        
        self.status_label = ttk.Label(button_frame, text="")
        self.status_label.pack(side=tk.LEFT, padx=20)
        
        # Output area with notebook
        output_frame = ttk.LabelFrame(self.root, text="Compilation Results")
        output_frame.grid(row=3, column=0, padx=10, pady=(0, 10), sticky="nsew")
        output_frame.columnconfigure(0, weight=1)
        output_frame.rowconfigure(0, weight=1)
        
        # Single output tab
        self.output_text = scrolledtext.ScrolledText(output_frame, wrap=tk.WORD, font=('Courier', 10))
        self.output_text.grid(row=0, column=0, padx=5, pady=5, sticky="nsew")
    
    def select_executable(self):
        """Allow the user to select the compiler executable"""
        executable_path = askopenfilename(
            title="Select the compiler executable",
            filetypes=[("Executable files", "*.exe *.out"), ("All files", "*.*")]
        )
        if executable_path:
            self.executable_path = executable_path
            self.status_label.config(text=f"Selected compiler: {os.path.basename(executable_path)}")
    
    def compile_code(self):
        """Compile the code entered in the input area"""
        code = self.code_input.get("1.0", tk.END).strip()
        
        if not code:
            messagebox.showwarning("Warning", "Please enter some code first")
            return
        
        # Create a temporary input file
        input_filename = "input.txt"
        try:
            with open(input_filename, "w") as f:
                f.write(code)
            
            # Update status
            self.status_label.config(text="Compiling...")
            self.root.update_idletasks()
            
            # If executable path is not set, try to find it or prompt user
            if not self.executable_path:
                # Try to find the executable in common locations
                possible_paths = [
                    "./a.out",                            # Unix current directory
                    "a.out",                              # Windows current directory
                    os.path.join(os.getcwd(), "a.out"),   # Full path current directory
                    os.path.join(os.getcwd(), "a.exe")    # Windows executable
                ]
                
                for path in possible_paths:
                    if os.path.isfile(path):
                        self.executable_path = path
                        break
                
                # If still not found, ask user to locate it
                if not self.executable_path:
                    response = messagebox.askquestion("Executable Not Found", 
                                                  "The compiler executable was not found. Would you like to locate it manually?")
                    if response == 'yes':
                        self.select_executable()
                    else:
                        self.status_label.config(text="Compilation cancelled")
                        return
            
            # If we still don't have a path, exit
            if not self.executable_path:
                self.status_label.config(text="No compiler selected")
                return
                
            # Run the compiler executable with the selected path
            try:
                os.system(f'.{self.executable_path} input.txt')
                
                # Check if the process completed successfully
                # if result.returncode != 0:
                #     self.status_label.config(text="Compilation failed")
                #     messagebox.showerror("Error", f"Compilation failed:\n{result.stderr}")
                #     return
                
                # Read the output files
                self.display_output_files()
                
                self.status_label.config(text="Compilation completed")
                
            except Exception as e:
                self.status_label.config(text="Error executing compiler")
                messagebox.showerror("Error", f"Failed to run compiler: {str(e)}")
                
        except Exception as e:
            self.status_label.config(text="Error occurred")
            messagebox.showerror("Error", f"An error occurred: {str(e)}")
    
    def display_output_files(self):
        """Read and display the content of output.txt file"""
        # Clear previous output
        self.output_text.delete(1.0, tk.END)
        
        # Read output.txt
        try:
            with open("output.txt", "r") as f:
                content = f.read()
                self.output_text.insert(tk.END, content)
        except FileNotFoundError:
            self.output_text.insert(tk.END, "Output file 'output.txt' not found.\n\nPlease make sure your compiler generates this file.")
        except Exception as e:
            self.output_text.insert(tk.END, f"Error reading output file: {str(e)}")
    
    def open_file(self):
        """Open a file and load its content into the code input area"""
        filename = askopenfilename(
            filetypes=[("Text Files", "*.txt"), ("All Files", "*.*")]
        )
        if not filename:
            return
        
        try:
            with open(filename, "r") as f:
                content = f.read()
                self.code_input.delete(1.0, tk.END)
                self.code_input.insert(tk.END, content)
                self.status_label.config(text=f"Opened: {os.path.basename(filename)}")
        except Exception as e:
            messagebox.showerror("Error", f"Could not open file: {str(e)}")
    
    def save_file(self):
        """Save the content of the code input area to a file"""
        code = self.code_input.get("1.0", tk.END)
        filename = asksaveasfilename(
            defaultextension=".txt",
            filetypes=[("Text Files", "*.txt"), ("All Files", "*.*")]
        )
        if not filename:
            return
        
        try:
            with open(filename, "w") as f:
                f.write(code)
                self.status_label.config(text=f"Saved: {os.path.basename(filename)}")
        except Exception as e:
            messagebox.showerror("Error", f"Could not save file: {str(e)}")


if __name__ == "__main__":
    root = tk.Tk()
    app = CompilerApp(root)
    root.mainloop()