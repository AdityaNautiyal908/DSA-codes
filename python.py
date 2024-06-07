import openai

# Replace with your actual OpenAI API key
openai.api_key = "sk-proj-4EICZsANdM1W57SvxXqGT3BlbkFJvt7AwJnS5I5220vdm2qT"

def chat_with_gpt(prompt):
    response = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=[
            {"role": "system", "content": "You are a helpful assistant."},
            {"role": "user", "content": prompt}
        ]
    )
    return response.choices[0].message['content'].strip()

def main():
    print("Chatbot is ready to talk! (type 'quit' to exit)")

    while True:
        user_input = input("You: ")
        if user_input.lower() in ["quit", "exit", "bye"]:
            print("Chatbot: Goodbye!")
            break

        response = chat_with_gpt(user_input)
        print("Chatbot:", response)

if __name__ == "__main__":
    main()
