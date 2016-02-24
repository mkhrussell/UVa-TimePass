.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-11799 - Debug ]----------"
	@cd "UVa-11799" && "$(MAKE)" -f  "UVa-11799.mk"
clean:
	@echo "----------Cleaning project:[ UVa-11799 - Debug ]----------"
	@cd "UVa-11799" && "$(MAKE)" -f  "UVa-11799.mk" clean
