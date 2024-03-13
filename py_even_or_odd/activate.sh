#!/bin/zsh

if [ ! -d "venv" ]; then
    # Create a virtual environment
    python3 -m venv venv
    echo "venv created."
fi

# Activate the virtual environment
source venv/bin/activate

# Install requirements
pip install -r requirements.txt
